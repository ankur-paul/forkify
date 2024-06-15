'use strict';
import * as model from './model.js';
import { MODAL_CLOSE_SEC } from './config.js';
import recipeView from './views/recipeView.js';
import searchView from './views/searchView.js';
import resultView from './views/resultView.js';
import paginationView from './views/paginationView.js';
import bookmarksView from './views/bookmarksView.js';
import addRecipeView from './views/addRecipeView.js';
import 'core-js/stable';
import 'regenerator-runtime/runtime';
import { async } from 'regenerator-runtime';

// if (module.hot) {
//   module.hot.accept();
// }

const controlRecipes = async function () {
  try {
    const id = window.location.hash.slice(1);
    if (!id) return;

    recipeView.renderSpinner();

    //0. Update results and bookmarks view
    resultView.update(model.getSearchResultsPage());
    bookmarksView.update(model.state.bookmarks);

    //1. Loading recipe
    await model.loadRecipe(id);

    //2. Rendering Recipe
    recipeView.render(model.state.recipe);
    console.log(model.state.recipe);
  } catch (err) {
    recipeView.renderError();
    console.log(err);
  }
};

const controlSearchResults = async function () {
  try {
    resultView.renderSpinner();

    // 1. Get Search query
    const query = searchView.getQuery();
    if (!query) return;

    // 2.Load Search Result
    await model.loadSearchResults(query);

    // 3. Render Search Result
    // resultView.render(model.state.search.result);
    resultView.render(model.getSearchResultsPage());

    // 4. Render initial pagination buttons:
    paginationView.render(model.state.search);
  } catch (err) {
    console.log(err);
  }
};

const controlPagination = function (goTopage) {
  resultView.render(model.getSearchResultsPage(goTopage));
  paginationView.render(model.state.search);
};

const controlServings = function (newServings) {
  // Update servings
  model.updateservings(newServings);

  // Render data according to new servings
  recipeView.update(model.state.recipe);
};

const controlBookmarks = function () {
  // 1. Add/ Remove Bookmark
  if (model.state.recipe.bookmarked)
    model.deleteBookmark(model.state.recipe.id);
  else model.bookmark(model.state.recipe);

  // 2. Update the recipe view
  recipeView.update(model.state.recipe);

  // 3. Render Bookmark
  bookmarksView.render(model.state.bookmarks);
};

const conntrolRenderBookmarks = function () {
  bookmarksView.render(model.state.bookmarks);
};

const controlAddRecipe = async function (recipe) {
  try {
    // 1. Upload Recipe
    const res = await model.uploadRecipe(recipe);
    console.log(model.state.recipe);

    // 2. Render Recipe
    recipeView.render(model.state.recipe);

    // 3. Render Bookmark
    bookmarksView.render(model.state.bookmarks);

    // 4. Render Success message
    addRecipeView.renderMessage();

    // 5. hide addRecipeView
    setTimeout(function () {
      addRecipeView.hideWindow();
    }, MODAL_CLOSE_SEC * 1000);

    // 6. Change ID in url
    window.history.pushState(null, '', `#${model.state.recipe.id}`);
  } catch (err) {
    addRecipeView.renderError(err);
    console.log(err);
  }
};

const init = function () {
  bookmarksView.addHandlerRenderBookmarks(conntrolRenderBookmarks);
  recipeView.addHandlerRender(controlRecipes);
  recipeView.addHandlerUpdateServings(controlServings);
  recipeView.addHandlerBookmark(controlBookmarks);
  searchView.addHandlerSearch(controlSearchResults);
  paginationView.addHandlerClick(controlPagination);
  addRecipeView.addHandlerUpload(controlAddRecipe);
};
init();
