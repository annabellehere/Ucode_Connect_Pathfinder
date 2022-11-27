#include "../inc/pathfinder.h"

void mx_check_validate(char *file, char *argv[]) {
    if (mx_strlen(file) == 0) {
        mx_strdel(&file);
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(0);
    }
    char **lines = mx_strsplit(file, '\n');
    int count = 0;
    for (int i = 0; i < mx_strlen(*lines); i++) if (lines[0] == NULL) count++;
    if (count == mx_strlen(*lines)) {
        mx_strdel(&file);
        mx_del_strarr(&lines);
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(0);
    }
    for (int i = 0; lines[0][i]; i++) {
        if(!mx_isdigit(lines[0][i])) {
            mx_strdel(&file);
            mx_del_strarr(&lines);
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
    }
    if (lines[0][0] == '0' || lines[0][0] == '-') {
        mx_strdel(&file);
        mx_del_strarr(&lines);
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }
    int lines_count = 0;
    while (lines[lines_count]) lines_count++;
    mx_check_lines(lines, lines_count, file);
    mx_del_strarr(&lines);
}

void mx_check_lines(char **lines, int lines_count, char *file) {
    for (int i = 1; i < lines_count; i++) {
        int chars_per_word = 0;
        int temp_chars = 0;
        chars_per_word = mx_check_alpha(lines, i, chars_per_word);
        mx_check_counts(chars_per_word, temp_chars, i, file, lines);
        if (lines[i][chars_per_word] != '-') {
            mx_strdel(&file);
            mx_del_strarr(&lines);
            mx_printerr_line(i + 1);
        }
        chars_per_word++;
        temp_chars = chars_per_word;
        chars_per_word = mx_check_alpha(lines, i, chars_per_word);
        mx_check_counts(chars_per_word, temp_chars, i, file, lines);
        if (lines[i][chars_per_word] != ',') {
            mx_strdel(&file);
            mx_del_strarr(&lines);
            mx_printerr_line(i + 1);
        }
        chars_per_word++;
        temp_chars = chars_per_word;
        while (mx_isdigit(lines[i][chars_per_word])) chars_per_word++;
        mx_check_counts(chars_per_word, temp_chars, i, file, lines);
        if (lines[i][chars_per_word] != '\0') {
            mx_strdel(&file);
            mx_del_strarr(&lines);
            mx_printerr_line(i + 1);
        }
    }
}

int mx_check_alpha(char **lines, int numOfLine, int indOfChar) {
    while (mx_isalpha(lines[numOfLine][indOfChar])) indOfChar++;
    return indOfChar;
}

void mx_printerr_line(int line) {
    mx_printerr("error: line ");
    char *output = mx_itoa(line);
    mx_printerr(output);
    mx_printerr(" is not valid\n");
    mx_strdel(&output);
    exit(0);
}

void mx_check_counts(int chars_per_word, int temp_chars, int line, char *file, char **lines) {
    if (chars_per_word == temp_chars) {
        mx_strdel(&file);
        mx_del_strarr(&lines);
        mx_printerr_line(line + 1);
    }
}



