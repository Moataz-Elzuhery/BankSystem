#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "clsString.h"
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
private:

    // =========================
    // Generic Template Helpers
    // =========================

    template <typename T>
    static bool _IsNumberBetween(T Number, T From, T To)
    {
        return (Number >= From && Number <= To);
    }

    template <typename T>
    static T _ReadNumber(string ErrorMessage)
    {
        T Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    template <typename T>
    static T _ReadNumberBetween(T From, T To, string ErrorMessage)
    {
        T Number = _ReadNumber<T>(ErrorMessage);

        while (!_IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = _ReadNumber<T>(ErrorMessage);
        }

        return Number;
    }

public:

    // =========================
    // IsNumberBetween (No Name Change)
    // =========================

    static bool IsNumberBetween(short Number, short From, short To)
    {
        return _IsNumberBetween(Number, From, To);
    }

    static bool IsNumberBetween(int Number, int From, int To)
    {
        return _IsNumberBetween(Number, From, To);
    }

    static bool IsNumberBetween(double Number, double From, double To)
    {
        return _IsNumberBetween(Number, From, To);
    }

    // =========================
    // Date Validation
    // =========================

    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
            &&
            (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
        {
            return true;
        }

        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
            &&
            (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
        {
            return true;
        }

        return false;
    }

    // =========================
    // Reading Numbers
    // =========================

    static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        return _ReadNumber<int>(ErrorMessage);
    }

    static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        return _ReadNumber<double>(ErrorMessage);
    }

    static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        return _ReadNumber<double>(ErrorMessage);
    }

    // =========================
    // Reading Numbers Between Range
    // =========================

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        return _ReadNumberBetween<int>(From, To, ErrorMessage);
    }

    static double ReadFloatNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        return _ReadNumberBetween<double>(From, To, ErrorMessage);
    }

    static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        return _ReadNumberBetween<double>(From, To, ErrorMessage);
    }


    static bool IsValideDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

    static string ReadString()
    {
        string S1 = "";
        getline(cin >> ws, S1);
        return S1;
    }

    static short ReadShortNumberBetween(short min, short max, const string& errorMessage)
    {
        return _ReadNumberBetween<short>(min, max, errorMessage);
    }
};
