//
// Created by Duc Vo on 2/7/22.
//

#ifndef MIDTERM_RANGECHECKER_H
#define MIDTERM_RANGECHECKER_H


class RangeChecker {
public:
    RangeChecker(int, int);
    ~RangeChecker();
    RangeChecker(const RangeChecker &);
    RangeChecker& operator=(const RangeChecker &);
    RangeChecker(RangeChecker &&);
    RangeChecker& operator=(RangeChecker &&);
    void hit(int);
private:
    int x, y, above, below, hitCount;



};


#endif //MIDTERM_RANGECHECKER_H
