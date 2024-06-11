import View from './View.js';
import previewView from './previewView.js';

class resultView extends View {
  _parentEl = document.querySelector('.results');
  _errorMsg = 'No matching result found for your query, Please try again :)';

  _generateMarkup() {
    return this._data.map(result => previewView.render(result, false)).join('');
  }
}

export default new resultView();
