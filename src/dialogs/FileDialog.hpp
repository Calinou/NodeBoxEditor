#ifndef FILEDIALOG_HPP_INCLUDED
#define FILEDIALOG_HPP_INCLUDED
#include "../common.hpp"
#include "../EditorState.hpp"

extern void FileDialog_open_project(EditorState *state);
extern void FileDialog_save_project(EditorState *state);
//extern void FileDialog_import(EditorState *state, FileFormatType parser);
extern void FileDialog_export(EditorState *state, int parser);

#endif
