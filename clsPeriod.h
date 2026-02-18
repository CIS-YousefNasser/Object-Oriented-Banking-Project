#pragma once
#include "clsDate.h"

class clsPeriod
{
public:

    clsDate startDate;
    clsDate endDate;

    clsPeriod(clsDate StartDate, clsDate DateTo)
    {
        this->startDate = StartDate;
        this->endDate = endDate;

    }

    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        if (
            clsDate::CompareDates(Period2.endDate, Period1.startDate) == clsDate::enDateCompare::Before
            ||
            clsDate::CompareDates(Period2.startDate, Period1.endDate) == clsDate::enDateCompare::After
            )
            return false;
        else
            return true;

    }


    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    void Print()
    {
        cout << "Period Start: ";
        startDate.Print();


        cout << "Period End: ";
        endDate.Print();


    }

};
