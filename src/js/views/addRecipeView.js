import View from './View.js';
import icons from 'url:../../img/icons.svg';

class AddRecipeView extends View {
  _parentEl = document.querySelector('.upload');
  _msg = 'Recipe was successfully added :)';
  _overlay = document.querySelector('.overlay');
  _window = document.querySelector('.add-recipe-window');
  _btnOpen = document.querySelector('.nav__btn--add-recipe');
  _btnClose = document.querySelector('.btn--close-modal');

  constructor() {
    super();
    this.#addHandlerShowWindow();
    this.#addHandlerCloseWindow();
  }

  toggleWindow() {
    this._overlay.classList.toggle('hidden');
    this._window.classList.toggle('hidden');
  }

  escClose() {}

  #addHandlerShowWindow() {
    // here we can also use arrow function so that this keyword is preserved for the class, instead of binding this to the callback fuction.
    this._btnOpen.addEventListener('click', this.toggleWindow.bind(this));
  }
  #addHandlerCloseWindow() {
    // here we can also use arrow function so that this keyword is preserved for the class, instead of binding this to the callback fuction.
    this._btnClose.addEventListener('click', this.toggleWindow.bind(this));
    this._overlay.addEventListener('click', this.toggleWindow.bind(this));
    document.addEventListener('keydown', e => {
      if (e.key === 'Escape' && !this._overlay.classList.contains('hidden')) {
        // this._overlay.classList.add('hidden');
        // this._window.classList.add('hidden');
        this.toggleWindow();
      }
    });
  }

  addHandlerUpload(handler) {
    this._parentEl.addEventListener('submit', function (e) {
      e.preventDefault();
      const dataArr = [...new FormData(this)];
      const data = Object.fromEntries(dataArr);
      handler(data);
    });
  }

  hideWindow() {
    this._overlay.classList.add('hidden');
    this._window.classList.add('hidden');
  }
}

export default new AddRecipeView();
