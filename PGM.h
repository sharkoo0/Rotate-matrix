#pragma once
#include <iostream>
#include <fstream>
#include <string>

class PGM {
private:
    int** image;
    int height;
    int width;
    std::string fileName;

    void copy(const PGM& pgm) {
        height = pgm.height;
        width = pgm.width;
        image = new int*[height];
        for (int i = 0; i < height; ++i) {
            image[i] = new int[width];
        }
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                image[i][j] = pgm.image[i][j];
            }
        }
    }

    void erase() {
        for (int i = 0; i < height; ++i) {
            delete[] image[i];
        }
        delete[] image;
    }

    int strToInt(std::string str) {
        int number = 0;
        std::cout << "str: " << str << std::endl;
        for (int i = 0; i < str.length(); ++i) {
            number += str[i] - '0';
        }

        return number;
    }

    void saveToFile(std::ostream& os) {
        os << height;
        os << " ";
        os << width;
        os << "\n";
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                os << image[i][j];
            }
            os << "\n";
        }
    }

    void readFromFile(std::istream& is) {
        if(!is) {
            height = 1;
            width = 1;
            image = new int*[height];
            image[0] = new int[width];
            image[0][0] = 0;
            return;
        }
        std::string row;
        int r = 0;
        int c = 0;
        is >> row;
        height = strToInt(row.substr(0, row.find(' ')));
        is >> row;
        width = strToInt(row.substr(row.find(' ') + 1));

        image = new int*[height];
        for (int i = 0; i < height; ++i) {
            image[i] = new int[width];
        }

        while(!is.eof()) {
            is >> row;
            for (int i = 0; i < row.length(); ++i) {
                image[r][c++] = row[i] - '0';
            }
            ++r;
            c = 0;
        }
    }

public:
    PGM() {
        height = 1;
        width = 1;
        image = new int*[height];
        image[0] = new int[width];
        image[0][0] = 0;
    }

    PGM(const PGM& pgm) {
        copy(pgm);
    }

    PGM& operator=(const PGM& pgm) {
        if (this != &pgm) {
            erase();
        }
        copy(pgm);
        return *this;
    }

    ~PGM() {
        erase();
    }

    PGM(int height, int width) {
        this->height = height;
        this->width = width;
        image = new int*[height];
        for (int i = 0; i < height; ++i) {
            image[i] = new int[width];
        }
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                image[i][j] = 0;
            }
        }
    }

    PGM(std::string fileName) {
        std::ifstream ifstr(fileName);
        readFromFile(ifstr);
        ifstr.close();
        this->fileName = fileName;
    }

    void print() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                std::cout << image[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    int getHeight() const {
        return height;
    }

    int getWidth() const {
        return width;
    }

    int** getImage() {
        return image;
    }

    void setImage(int** image, int row, int col) {
        erase();
        this->image = new int*[row];
        for (int i = 0; i < row; ++i) {
            this->image[i] = new int[col];
        }
        height = row;
        width = col;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                this->image[i][j] = image[i][j];
                
            }
        }
        std::ofstream os(fileName);
        saveToFile(os);
    }    
};