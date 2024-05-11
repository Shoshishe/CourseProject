//
// Created by shosh on 5/11/24.
//

#ifndef COURSE_PROJECT_RANDOMISAION_H
#define COURSE_PROJECT_RANDOMISAION_H

#endif //COURSE_PROJECT_RANDOMISAION_H
#include "QTime"

static const char* salt = "afec26qrtbewOEQ2K[PIJO";
static const unsigned int salt_length = 22;

unsigned int MurmurHash2 (const char * key, unsigned int len);
unsigned int xorShift(unsigned int x);