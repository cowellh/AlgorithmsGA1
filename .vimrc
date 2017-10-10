"Keybindings
inoremap jk <esc>
"set backspace=indent,eol,start " backspace fix
"Unknown
filetype on
filetype plugin on
autocmd Filetype c,cpp set cindent

"Tab settings
set sw=2 " number of spaces in a tab when editing
set ts=2 " number of visual spaces per tab character
set expandtab " makes tab input spaces

"Ui Customization
set number	" turns on line numberso
set showcmd " show command in bottom bar
syntax on 	" turn on syntax coloring

"set cursorline " highlights the current line
colorscheme slate	" set colorscheme
filetype indent on " turns on filetype indentation and allows language specific libraries to be loaded
set wildmenu " turns on autcomplete menu
set showmatch " shows matching parenthesis
set showmode " shows current mode

"Search Customization
set incsearch " search as characters are entered
set hlsearch  " highlight matches

"Folding
""set foldenable " enable folding
"set foldlevelstart = 10 " open folds by default

"Movement
nnoremap j gj
nnoremap k gk
