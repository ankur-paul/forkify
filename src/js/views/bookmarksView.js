import { bookmark } from '../model.js';
import View from './View.js';
import previewView from './previewView.js';
import icons from 'url:../../img/icons.svg';

class BookmarksView extends View {
  _parentEl = document.querySelector('.bookmarks__list');
  _errorMsg = 'No bookmarks yet. Find a nice recipe and bookmark it :)';

  addHandlerRenderBookmarks(handler) {
    window.addEventListener('load', handler);
  }

  _generateMarkup() {
    if (!this._data) return;
    return this._data
      .map(bookmark => previewView.render(bookmark, false))
      .join('');
  }
}

export default new BookmarksView();
