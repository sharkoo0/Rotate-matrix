#pragma once
#include <iostream>
#include "PGM.h"

class PGMhelper {
private:
    void rotate90(PGM& pgm) {
        int rows = pgm.getWidth(), cols = pgm.getHeight();
        int **image = new int*[rows];
        int **copyImage = pgm.getImage();

        for(int i = 0; i < rows; ++i) {
            image[i] = new int[cols];
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                image[i][j] = copyImage[cols - j - 1][i];
            }
        }
        
        pgm.setImage(image, rows, cols);
    }
    
public:
    void rotate(PGM& pgm, int degree) {
        switch (degree)
        {
        case -90:
            rotate90(pgm);
            rotate90(pgm);
            rotate90(pgm);
            break;
        case 90:
            rotate90(pgm);
            break;
        case 180:
            rotate90(pgm);
            rotate90(pgm);
            break;
        default:
            break;
        }
    }
};