#pragma once

#include <iostream>
#include <vector>

class clsString
{

private:
    std::string _text;

public:

    clsString()
    {
        _text = "";
    }

    clsString(std::string text)
    {
        _text = text;
    }

    void SetValue(std::string text) {
        _text = text;
    }

    std::string GetValue() {
        return _text;
    }

    __declspec(property(get = GetValue, put = SetValue)) std::string text;


    static short Length(std::string s1)
    {
        return s1.length();
    };

    short Length()
    {
        return _text.length();
    };

    static short CountWords(std::string s1)
    {

        std::string delimiter = " ";
        short counter = 0;
        short pos = 0;
        std::string sWord;
        while ((pos = s1.find(delimiter)) != std::string::npos)
        {
            sWord = s1.substr(0, pos);
            if (sWord != "")
            {
                counter++;
            }
            s1.erase(0, pos + delimiter.length());
        }

        if (s1 != "")
        {
            counter++;
        }

        return counter;

    }
    short CountWords()
    {
        return CountWords(_text);
    };

    static std::string  UpperFirstLetterOfEachWord(std::string s1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < s1.length(); i++)
        {

            if (s1[i] != ' ' && isFirstLetter)
            {
                s1[i] = toupper(s1[i]);

            }

            isFirstLetter = (s1[i] == ' ' ? true : false);

        }

        return s1;
    }

    void  UpperFirstLetterOfEachWord()
    {
        _text = UpperFirstLetterOfEachWord(_text);
    }

    static std::string  LowerFirstLetterOfEachWord(std::string s1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < s1.length(); i++)
        {

            if (s1[i] != ' ' && isFirstLetter)
            {
                s1[i] = tolower(s1[i]);

            }

            isFirstLetter = (s1[i] == ' ' ? true : false);

        }

        return s1;
    }

    void  LowerFirstLetterOfEachWord()
    {
        _text = LowerFirstLetterOfEachWord(_text);
    }

    static std::string  UpperAllString(std::string s1)
    {
        for (short i = 0; i < s1.length(); i++)
        {
            s1[i] = toupper(s1[i]);
        }
        return s1;
    }

    void UpperAllString()
    {
        _text = UpperAllString(_text);
    }

    static std::string  LowerAllString(std::string s1)
    {
        for (short i = 0; i < s1.length(); i++)
        {
            s1[i] = tolower(s1[i]);
        }
        return s1;
    }

    void  LowerAllString()
    {
        _text = LowerAllString(_text);
    }

    static char  InvertLetterCase(char char1)
    {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }

    static std::string  InvertAllLettersCase(std::string s1)
    {
        for (short i = 0; i < s1.length(); i++)
        {
            s1[i] = InvertLetterCase(s1[i]);
        }
        return s1;
    }

    void  InvertAllLettersCase()
    {
        _text = InvertAllLettersCase(_text);
    }

    enum enWhatToCount { smallLetters = 0, capitalLetters = 1, all = 3 };

    static short CountLetters(std::string s1, enWhatToCount whatToCount = enWhatToCount::all)
    {


        if (whatToCount == enWhatToCount::all)
        {
            return s1.length();
        }

        short counter = 0;

        for (short i = 0; i < s1.length(); i++)
        {

            if (whatToCount == enWhatToCount::capitalLetters && isupper(s1[i]))
                counter++;


            if (whatToCount == enWhatToCount::smallLetters && islower(s1[i]))
                counter++;


        }

        return counter;

    }

    static short  CountCapitalLetters(std::string s1)
    {

        short counter = 0;

        for (short i = 0; i < s1.length(); i++)
        {

            if (isupper(s1[i]))
                counter++;

        }

        return counter;
    }

    short  CountCapitalLetters()
    {
        return CountCapitalLetters(_text);
    }

    static short  CountSmallLetters(std::string s1)
    {

        short counter = 0;

        for (short i = 0; i < s1.length(); i++)
        {

            if (islower(s1[i]))
                counter++;

        }

        return counter;
    }

    short  CountSmallLetters()
    {
        return CountSmallLetters(_text);
    }

    static short  CountSpecificLetter(std::string s1, char letter, bool matchCase = true)
    {

        short counter = 0;

        for (short i = 0; i < s1.length(); i++)
        {

            if (matchCase)
            {
                if (s1[i] == letter)
                    counter++;
            }
            else
            {
                if (tolower(s1[i]) == tolower(letter))
                    counter++;
            }

        }

        return counter;
    }

    short  CountSpecificLetter(char letter, bool matchCase = true)
    {
        return CountSpecificLetter(_text, letter, matchCase);
    }

    static bool IsVowel(char ch1)
    {
        ch1 = tolower(ch1);

        return ((ch1 == 'a') || (ch1 == 'e') || (ch1 == 'i') || (ch1 == 'o') || (ch1 == 'u'));

    }

    static short  CountVowels(std::string s1)
    {

        short counter = 0;

        for (short i = 0; i < s1.length(); i++)
        {

            if (IsVowel(s1[i]))
                counter++;

        }

        return counter;
    }

    short  CountVowels()
    {
        return CountVowels(_text);
    }

    static std::vector<std::string> Split(std::string s1, std::string delimiter)
    {

        std::vector<std::string> vString;

        short pos = 0;
        std::string sWord;

        while ((pos = s1.find(delimiter)) != std::string::npos)
        {
            sWord = s1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                vString.push_back(sWord);
            }

            s1.erase(0, pos + delimiter.length());
        }

        if (s1 != "")
        {
            vString.push_back(s1);
        }

        return vString;

    }

    std::vector<std::string> Split(std::string delimiter)
    {
        return Split(_text, delimiter);
    }

    static std::string TrimLeft(std::string S1)
    {


        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }

    void TrimLeft()
    {
        _text = TrimLeft(_text);
    }

    static std::string TrimRight(std::string s1)
    {


        for (short i = s1.length() - 1; i >= 0; i--)
        {
            if (s1[i] != ' ')
            {
                return s1.substr(0, i + 1);
            }
        }
        return "";
    }

    void TrimRight()
    {
        _text = TrimRight(_text);
    }

    static std::string Trim(std::string s1)
    {
        return (TrimLeft(TrimRight(s1)));

    }

    void Trim()
    {
        _text = Trim(_text);
    }

    static std::string JoinString(std::vector<std::string> vString, std::string delimiter)
    {

        std::string s1 = "";

        for (std::string& s : vString)
        {
            s1 = s1 + s + delimiter;
        }

        return s1.substr(0, s1.length() - delimiter.length());


    }

    static std::string JoinString(std::string arrString[], short length, std::string delimiter)
    {

        std::string s1 = "";

        for (short i = 0; i < length; i++)
        {
            s1 = s1 + arrString[i] + delimiter;
        }

        return s1.substr(0, s1.length() - delimiter.length());

    }

    static std::string ReverseWordsInString(std::string s1)
    {

        std::vector<std::string> vString;
        std::string s2 = "";

        vString = Split(s1, " ");

        // declare iterator
        std::vector<std::string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {

            --iter;

            s2 += *iter + " ";

        }

        s2 = s2.substr(0, s2.length() - 1);

        return s2;
    }

    void ReverseWordsInString()
    {
        _text = ReverseWordsInString(_text);
    }

    static std::string ReplaceWord(std::string s1, std::string stringToReplace, std::string sRepalceTo, bool matchCase = true)
    {

        std::vector<std::string> vString = Split(s1, " ");

        for (std::string& s : vString)
        {

            if (matchCase)
            {
                if (s == stringToReplace)
                {
                    s = sRepalceTo;
                }

            }
            else
            {
                if (LowerAllString(s) == LowerAllString(stringToReplace))
                {
                    s = sRepalceTo;
                }

            }

        }

        return JoinString(vString, " ");
    }

    std::string ReplaceWord(std::string stringToReplace, std::string sRepalceTo)
    {
        return ReplaceWord(_text, stringToReplace, sRepalceTo);
    }

    static std::string RemovePunctuations(std::string s1)
    {

        std::string s2 = "";

        for (short i = 0; i < s1.length(); i++)
        {
            if (!ispunct(s1[i]))
            {
                s2 += s1[i];
            }
        }

        return s2;

    }

    void RemovePunctuations()
    {
        _text = RemovePunctuations(_text);
    }


};

