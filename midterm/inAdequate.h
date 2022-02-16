//
// Created by Duc Vo on 2/7/22.
//

#ifndef MIDTERM_INADEQUATE_H
#define MIDTERM_INADEQUATE_H


class inAdequate {
private:
    static const int DEFAULT_NUM = 1;
    int* data;
    int num;

public:
    inAdequate(int num = DEFAULT_NUM);
    ~inAdequate();
//    inAdequate(const inAdequate &);
    inAdequate& operator=(const inAdequate &);
//    inAdequate& operator=(inAdequate &&);
};


#endif //MIDTERM_INADEQUATE_H
