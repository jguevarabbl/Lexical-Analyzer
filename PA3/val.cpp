#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "val.h"

Value Value::operator+(const Value& op) const //ADDITION
{
    double oper1, oper2;
    if (IsString() && op.IsString())
    {
        try
        {
            oper1 = stod(GetString());
            oper2 = stod(op.GetString());
            double result = oper1 + oper2;
            return Value(result);
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (IsString() && (op.IsInt() || op.IsReal()))
    {
        try
        {
            oper1 = stod(GetString());
            if (op.IsInt())
            {
                double result = oper1 + op.GetInt();
                return Value(result);
            }
            else if (op.IsReal())
            {
                double result = oper1 + op.GetReal();
                return Value(result);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if ((IsInt() || IsReal()) && op.IsString())
    {
        try
        {
            oper1 = stod(op.GetString());
            if (IsInt())
            {
                double result = GetInt() + oper1;
                return Value(result);
            }
            else if (IsReal())
            {
                double result = GetReal() + oper1;
                return Value(result);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if ((IsInt() || IsReal()) && (op.IsInt() || op.IsReal()))
    {
        if (IsInt() && op.IsInt())
        {
            double result = GetInt() + op.GetInt();
            return Value(result);
        }
        else if (IsInt() && op.IsReal())
        {
            double result = GetInt() + op.GetReal();
            return Value(result);
        }
        else if (IsReal() && op.IsReal())
        {
            double result = GetReal() + op.GetReal();
            return Value(result);
        }
        else if (IsReal() && op.IsInt())
        {
            double result = GetReal() + op.GetInt();
            return Value(result);
        }
        //double result = GetReal() + op.GetReal();
       // return Value(result);
    }
    return Value();
}
//------------------------------------------------------------------------------------------------------------------
Value Value::operator-(const Value& op) const //SUBTRACTION
{
    double oper1, oper2;
    if (IsString() && op.IsString())
    {
        try
        {
            oper1 = stod(GetString());
            oper2 = stod(op.GetString());
            double result = oper1 - oper2;
            return Value(result);
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (IsString() && (op.IsInt() || op.IsReal()))
    {
        try
        {
            oper1 = stod(GetString());
            if (op.IsInt())
            {
                double result = oper1 - op.GetInt();
                return Value(result);
            }
            else if (op.IsReal())
            {
                double result = oper1 - op.GetReal();
                return Value(result);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if ((IsInt() || IsReal()) && op.IsString())
    {
        try
        {
            oper1 = stod(op.GetString());
            if (IsInt())
            {
                double result = GetInt() - oper1;
                return Value(result);
            }
            else if (IsReal())
            {
                double result = GetReal() - oper1;
                return Value(result);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if ((IsInt() || IsReal()) && (op.IsInt() || op.IsReal()))
    {
        if (IsInt() && op.IsInt())
        {
            double result = GetInt() - op.GetInt();
            return Value(result);
        }
        else if (IsInt() && op.IsReal())
        {
            double result = GetInt() - op.GetReal();
            return Value(result);
        }
        else if (IsReal() && op.IsReal())
        {
            double result = GetReal() - op.GetReal();
            return Value(result);
        }
        else if (IsReal() && op.IsInt())
        {
            double result = GetReal() - op.GetInt();
            return Value(result);
        }
        //double result = GetReal() + op.GetReal();
       // return Value(result);
    }
    return Value();
}
//------------------------------------------------------------------------------------------------------------------
Value Value::operator*(const Value& op) const //MULTIPLICATION
{
    double oper1, oper2;
    if (IsString() && op.IsString())
    {
        try
        {
            oper1 = stod(GetString());
            oper2 = stod(op.GetString());
            double result = oper1 * oper2;
            return Value(result);
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (IsString() && (op.IsInt() || op.IsReal()))
    {
        try
        {
            oper1 = stod(GetString());
            if (op.IsInt())
            {
                double result = oper1 * op.GetInt();
                return Value(result);
            }
            else if (op.IsReal())
            {
                double result = oper1 * op.GetReal();
                return Value(result);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if ((IsInt() || IsReal()) && op.IsString())
    {
        try
        {
            oper1 = stod(op.GetString());
            if (IsInt())
            {
                double result = GetInt() * oper1;
                return Value(result);
            }
            else if (IsReal())
            {
                double result = GetReal() * oper1;
                return Value(result);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if ((IsInt() || IsReal()) && (op.IsInt() || op.IsReal()))
    {
        if (IsInt() && op.IsInt())
        {
            double result = GetInt() * op.GetInt();
            return Value(result);
        }
        else if (IsInt() && op.IsReal())
        {
            double result = GetInt() * op.GetReal();
            return Value(result);
        }
        else if (IsReal() && op.IsReal())
        {
            double result = GetReal() * op.GetReal();
            return Value(result);
        }
        else if (IsReal() && op.IsInt())
        {
            double result = GetReal() * op.GetInt();
            return Value(result);
        }
    }
    return Value();
}
//------------------------------------------------------------------------------------------------------------------
Value Value::operator/(const Value& op) const //DIVISION
{
    double oper1, oper2;
    if (IsString() && op.IsString())
    {
        try
        {
            oper1 = stod(GetString());
            oper2 = stod(op.GetString());
            if (oper2 == 0)
            {
                return Value(); //DIVISION BY 0 ERROR
            }
            double result = oper1 / oper2;
            return Value(result);
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (IsString() && (op.IsInt() || op.IsReal()))
    {
        try
        {
            oper1 = stod(GetString());
            if (op.IsInt() && op.GetInt() != 0)
            {
                double result = oper1 / op.GetInt();
                return Value(result);
            }
            else if (op.IsReal() && op.GetReal() != 0)
            {
                double result = oper1 / op.GetReal();
                return Value(result);
            }
            else
            {
                return Value(); // DIVISION BY 0 ERROR
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if ((IsInt() || IsReal()) && op.IsString())
    {
        try
        {
            oper1 = stod(op.GetString());
            if (oper1 == 0)
            {
                return Value(); //DIVISON BY 0 ERROR;
            }
            else if (IsInt())
            {
                double result = GetInt() / oper1;
                return Value(result);
            }
            else if (IsReal())
            {
                double result = GetReal() / oper1;
                return Value(result);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if ((IsInt() || IsReal()) && (op.IsInt() || op.IsReal()))
    {
        if (IsInt() && op.IsInt())
        {
            if (op.GetInt() != 0)
            {
                double result = GetInt() / op.GetInt();
                return Value(result);
            }
            return Value(); //DIVISON BY 0 ERROR;
        }
        else if (IsInt() && op.IsReal())
        {
            if (op.GetReal() != 0)
            {
                double result = GetInt() / op.GetReal();
                return Value(result);
            }
            return Value(); //DIVISON BY 0 ERROR;
        }
        else if (IsReal() && op.IsReal())
        {
            if (op.GetReal() != 0)
            {
                double result = GetReal() / op.GetReal();
                return Value(result);
            }
            return Value(); //DIVISON BY 0 ERROR;
        }
        else if (IsReal() && op.IsInt())
        {
            if (op.GetInt() != 0);
            {
                double result = GetReal() / op.GetInt();
                return Value(result);
            }
            return Value(); //DIVISON BY 0 ERROR;
        }
    }
    return Value();
}
//------------------------------------------------------------------------------------------------------------------
Value Value::operator^(const Value& oper) const //EXPONENT
{
    if (IsInt() && oper.IsInt())
    {
        double result = pow(GetInt(), oper.GetInt());
        return Value(result);
    }
    else if (IsReal() && oper.IsReal())
    {
        double result = pow(GetReal(), oper.GetReal());
        return Value(result);
    }
    else if (IsInt() && oper.IsReal())
    {
        double result = pow(GetInt(), oper.GetReal());
        return Value(result);
    }
    else if (IsReal() && oper.IsInt())
    {
        double result = pow(GetReal(), oper.GetInt());
        return Value(result);
    }
    return Value();
}
//------------------------------------------------------------------------------------------------------------------
Value Value::operator==(const Value& op) const //DOUBLEEQ OPERATOR
{
    double oper1, oper2;
    if (IsString() && op.IsString())
    {
        try
        {
            oper1 = stod(GetString());
            oper2 = stod(op.GetString());
            if (oper1 == oper2)
            {
                return Value(true);
            }
            return Value(false);
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (IsString() && (op.IsInt() || op.IsReal()))
    {
        try
        {
            oper1 = stod(GetString());
            if (op.IsInt())
            {
                if (oper1 == op.GetInt())
                {
                    return Value(true);
                }
                return Value(false);
            }
            if (op.IsReal())
            {
                if (oper1 == op.GetReal())
                {
                    return Value(true);
                }
                return Value(false);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }

    }
    else if ((IsInt() || IsReal()) && op.IsString())
    {
        try
        {
            oper1 = stod(op.GetString());
            if (IsInt())
            {
                if (GetInt() == oper1)
                {
                    return Value(true);
                }
                return Value(false);
            }
            if (IsReal())
            {
                if (GetReal() == oper1)
                {
                    return Value(true);
                }
                return Value(false);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if ((IsInt() || IsReal()) && (op.IsInt() || op.IsReal()))
    {
        if (IsInt() && op.IsInt())
        {
            if (IsInt() == op.GetInt())
            {
                return Value(true);
            }
            return Value(false);
        }
        else if (IsInt() && op.IsReal())
        {
            if (IsInt() == op.GetReal())
            {
                return Value(true);
            }
            return Value(false);
        }
        else if (IsReal() && op.IsReal())
        {
            if (GetReal() == op.GetReal())
            {
                return Value(true);
            }
            return Value(false);
        }
        else if (IsReal() && op.IsInt())
        {
            if (GetReal() == op.GetInt())
            {
                return Value(true);
            }
            return Value(false);
        }
    }
    return Value();
}
//------------------------------------------------------------------------------------------------------------------
Value Value::operator<(const Value& op) const //LESS THAN OPERATOR
{
    double oper1, oper2;
    if (IsString() && op.IsString())
    {
        try
        {
            oper1 = stod(GetString());
            oper2 = stod(op.GetString());
            if (oper1 < oper2)
            {
                return Value(true);
            }
            return Value(false);
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (IsString() && (op.IsInt() || op.IsReal()))
    {
        try
        {
            oper1 = stod(GetString());
            if (op.IsInt())
            {
                if (oper1 < op.GetInt())
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (op.IsReal())
            {
                if (oper1 < op.GetReal())
                {
                    return Value(true);
                }
                return Value(false);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }

    }
    else if ((IsInt() || IsReal()) && op.IsString())
    {
        try
        {
            oper1 = stod(op.GetString());
            if (IsInt())
            {
                if (GetInt() < oper1)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (IsReal())
            {
                if (GetReal() < oper1)
                {
                    return Value(true);
                }
                return Value(false);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if ((IsInt() || IsReal()) && (op.IsInt() || op.IsReal()))
    {
        if (IsInt() && op.IsInt())
        {
            if (IsInt() < op.GetInt())
            {
                return Value(true);
            }
            return Value(false);
        }
        else if (IsInt() && op.IsReal())
        {
            if (IsInt() < op.GetReal())
            {
                return Value(true);
            }
            return Value(false);
        }
        else if (IsReal() && op.IsReal())
        {
            if (GetReal() < op.GetReal())
            {
                return Value(true);
            }
            return Value(false);
        }
        else if (IsReal() && op.IsInt())
        {
            if (GetReal() < op.GetInt())
            {
                return Value(true);
            }
            return Value(false);
        }
    }
    return Value();
}
//------------------------------------------------------------------------------------------------------------------
Value Value::operator>(const Value& op) const //GREATER THAN OPERATOR
{
    double oper1, oper2;
    if (IsString() && op.IsString())
    {
        try
        {
            oper1 = stod(GetString());
            oper2 = stod(op.GetString());
            if (oper1 > oper2)
            {
                return Value(true);
            }
            return Value(false);
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (IsString() && (op.IsInt() || op.IsReal()))
    {
        try
        {
            oper1 = stod(GetString());
            if (op.IsInt())
            {
                if (oper1 > op.GetInt())
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (op.IsReal())
            {
                if (oper1 > op.GetReal())
                {
                    return Value(true);
                }
                return Value(false);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }

    }
    else if ((IsInt() || IsReal()) && op.IsString())
    {
        try
        {
            oper1 = stod(op.GetString());
            if (IsInt())
            {
                if (GetInt() > oper1)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (IsReal())
            {
                if (GetReal() > oper1)
                {
                    return Value(true);
                }
                return Value(false);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if ((IsInt() || IsReal()) && (op.IsInt() || op.IsReal()))
    {
        if (IsInt() && op.IsInt())
        {
            if (IsInt() > op.GetInt())
            {
                return Value(true);
            }
            return Value(false);
        }
        else if (IsInt() && op.IsReal())
        {
            if (IsInt() > op.GetReal())
            {
                return Value(true);
            }
            return Value(false);
        }
        else if (IsReal() && op.IsReal())
        {
            if (GetReal() > op.GetReal())
            {
                return Value(true);
            }
            return Value(false);
        }
        else if (IsReal() && op.IsInt())
        {
            if (GetReal() > op.GetInt())
            {
                return Value(true);
            }
            return Value(false);
        }
    }
    return Value();
}
//------------------------------------------------------------------------------------------------------------------
Value Value::Catenate(const Value& oper) const //CONCATENTATION (.)
{
    string str1, str2, newstr = "";
    stringstream ss;
    if (IsString() && oper.IsString())
    {
        newstr = GetString() + oper.GetString();
        return Value(newstr);
    }
    else if (IsString() && !oper.IsString())
    {
        try
        {
            if (oper.IsInt())
            {
                ss << oper.GetInt();
                newstr = GetString() + ss.str();
                return Value(newstr);
            }
            else if (oper.IsReal())
            {
                ss << oper.GetReal();
                newstr = GetString() + ss.str();
                return Value(newstr);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (!IsString() && oper.IsString())
    {
        try
        {
            if (IsInt())
            {
                ss << GetInt();
                newstr = ss.str() + oper.GetString();
                return Value(newstr);
            }
            else if (IsReal())
            {
                ss << GetReal();
                newstr = ss.str() + oper.GetString();
                return Value(newstr);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (!IsString() && !oper.IsString())
    {
        try
        {
            if (IsInt() && oper.IsInt())
            {
                ss << GetInt() << oper.GetInt();
                newstr = ss.str();
                return Value(newstr);
            }
            else if (IsInt() && oper.IsReal())
            {
                ss << GetInt() << oper.GetReal();
                newstr = ss.str();
                return Value(newstr);
            }
            else if (IsReal() && oper.IsReal())
            {
                ss << GetReal() << oper.GetReal();
                newstr = ss.str();
                return Value(newstr);
            }
            else if (IsReal() && oper.IsInt())
            {
                ss << GetReal() << oper.GetInt();
                newstr = ss.str();
                return Value(newstr);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    return Value();
}
//------------------------------------------------------------------------------------------------------------------
Value Value::Repeat(const Value& oper) const // STRING REPEAT
{
    stringstream ss;
    double oper1;
    string str1, str2;
    if (IsString() && oper.IsString())
    {
        try
        {
            oper1 = stod(oper.GetString());
            int counter = oper1;
            string str = GetString(), newstr = "";
            for (int i = 1; i <= counter; i++)
            {
                newstr.append(str);
            }
            return Value(newstr);
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (IsString() && !oper.IsString())
    {
        try
        {
            if (oper.IsInt())
            {
                oper1 = oper.GetInt();
                int counter = oper1;
                string str = GetString(), newstr = "";
                for (int i = 1; i <= counter; i++)
                {
                    newstr.append(str);
                }
                return Value(newstr);
            }
            else if (oper.IsReal())
            {
                oper1 = oper.GetReal();
                int counter = oper1;
                string str = GetString(), newstr = "";
                for (int i = 1; i <= counter; i++)
                {
                    newstr.append(str);
                }
                return Value(newstr);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (!IsString() && oper.IsString())
    {
        try
        {
            if (IsInt())
            {
                ss << GetInt();
                oper1 = stod(oper.GetString());
                int counter = oper1;
                string newstr = "";
                for (int i = 1; i <= counter; i++)
                {
                    newstr.append(ss.str());
                }
                return Value(newstr);
            }
            else if (IsReal())
            {
                ss << GetReal();
                oper1 = stod(oper.GetString());
                int counter = oper1;
                string newstr = "";
                for (int i = 1; i <= counter; i++)
                {
                    newstr.append(ss.str());
                }
                return Value(newstr);
            }

        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (!IsString() && !oper.IsString())
    {
        try
        {
            if (IsInt() && oper.IsInt())
            {
                ss << GetInt();
                oper1 = oper.GetInt();
                int counter = oper1;
                string newstr = "";
                for (int i = 1; i <= counter; i++)
                {
                    newstr.append(ss.str());
                }
                return Value(newstr);
            }
            else if (IsReal() && oper.IsReal())
            {
                ss << GetReal();
                oper1 = oper.GetReal();
                int counter = oper1;
                string newstr = "";
                for (int i = 1; i <= counter; i++)
                {
                    newstr.append(ss.str());
                }
                return Value(newstr);
            }
            else if (IsInt() && oper.IsReal())
            {
                ss << GetInt();
                oper1 = oper.GetReal();
                int counter = oper1;
                string newstr = "";
                for (int i = 1; i <= counter; i++)
                {
                    newstr.append(ss.str());
                }
                return Value(newstr);
            }
            else if (IsReal() && oper.IsInt())
            {
                ss << GetReal();
                oper1 = oper.GetInt();
                int counter = oper1;
                string newstr = "";
                for (int i = 1; i <= counter; i++)
                {
                    newstr.append(ss.str());
                }
                return Value(newstr);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    return Value();
}
//------------------------------------------------------------------------------------------------------------------
Value Value::SLthan(const Value& oper) const //STRING LESS THAN
{
    string str1, str2;
    stringstream ss;
    if (IsString() && oper.IsString())
    {
        if (GetString().compare(oper.GetString()) < 0)
        {
            return Value(true);
        }
        return false;
    }
    else if (IsString() && !oper.IsString())
    {
        try
        {
            if (oper.IsInt())
            {
                ss << oper.GetInt();
                if (GetString().compare(ss.str()) < 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (oper.IsReal())
            {
                ss << oper.GetReal();
                if (GetString().compare(ss.str()) < 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (!IsString() && oper.IsString())
    {
        try
        {
            if (IsInt())
            {
                ss << GetInt();
                if (ss.str().compare(oper.GetString()) < 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (IsReal())
            {
                ss << GetReal();
                if (ss.str().compare(oper.GetString()) < 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (!IsString() && !oper.IsString())
    {
        try
        {
            if (IsInt() && oper.IsInt())
            {
                ss << GetInt();
                ss >> str1; ss.clear();
                ss << oper.GetInt();
                ss >> str2;
                if (str1.compare(str2) < 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (IsReal() && oper.IsReal())
            {
                ss << GetReal();
                ss >> str1; ss.clear();
                ss << oper.GetReal();
                ss >> str2;
                if (str1.compare(str2) < 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (IsInt() && oper.IsReal())
            {
                ss << GetInt();
                ss >> str1; ss.clear();
                ss << oper.GetReal();
                ss >> str2;
                if (str1.compare(str2) < 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (IsReal() && oper.IsInt())
            {
                ss << GetReal();
                ss >> str1; ss.clear();
                ss << oper.GetInt();
                ss >> str2;
                if (str1.compare(str2) < 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    return Value();
}
//------------------------------------------------------------------------------------------------------------------
Value Value::SGthan(const Value& oper) const //STRING GREATER THAN
{
    string str1, str2;
    stringstream ss;
    if (IsString() && oper.IsString())
    {
        if (GetString().compare(oper.GetString()) > 0)
        {
            return Value(true);
        }
        return false;
    }
    else if (IsString() && !oper.IsString())
    {
        try
        {
            if (oper.IsInt())
            {
                ss << oper.GetInt();
                if (GetString().compare(ss.str()) > 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (oper.IsReal())
            {
                ss << oper.GetReal();
                if (GetString().compare(ss.str()) > 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (!IsString() && oper.IsString())
    {
        try
        {
            if (IsInt())
            {
                ss << GetInt();
                if (ss.str().compare(oper.GetString()) > 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (IsReal())
            {
                ss << GetReal();
                if (ss.str().compare(oper.GetString()) > 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (!IsString() && !oper.IsString())
    {
        try
        {
            if (IsInt() && oper.IsInt())
            {
                ss << GetInt();
                ss >> str1; ss.clear();
                ss << oper.GetInt();
                ss >> str2;
                if (str1.compare(str2) > 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (IsReal() && oper.IsReal())
            {
                ss << GetReal();
                ss >> str1; ss.clear();
                ss << oper.GetReal();
                ss >> str2;
                if (str1.compare(str2) > 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (IsInt() && oper.IsReal())
            {
                ss << GetInt();
                ss >> str1; ss.clear();
                ss << oper.GetReal();
                ss >> str2;
                if (str1.compare(str2) > 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (IsReal() && oper.IsInt())
            {
                ss << GetReal();
                ss >> str1; ss.clear();
                ss << oper.GetInt();
                ss >> str2;
                if (str1.compare(str2) > 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    return Value();
}
//------------------------------------------------------------------------------------------------------------------
Value Value::SEqual(const Value& oper) const //STRING EQUAL TO
{
    string str1, str2;
    stringstream ss;
    if (IsString() && oper.IsString())
    {
        if (GetString().compare(oper.GetString()) == 0)
        {
            return Value(true);
        }
        return false;
    }
    else if (IsString() && !oper.IsString())
    {
        try
        {
            if (oper.IsInt())
            {
                ss << oper.GetInt();
                if (GetString().compare(ss.str()) == 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (oper.IsReal())
            {
                ss << oper.GetReal();
                if (GetString().compare(ss.str()) == 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (!IsString() && oper.IsString())
    {
        try
        {
            if (IsInt())
            {
                ss << GetInt();
                if (ss.str().compare(oper.GetString()) == 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (IsReal())
            {
                ss << GetReal();
                if (ss.str().compare(oper.GetString()) == 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (!IsString() && !oper.IsString())
    {
        try
        {
            if (IsInt() && oper.IsInt())
            {
                ss << GetInt();
                ss >> str1; ss.clear();
                ss << oper.GetInt();
                ss >> str2;
                if (str1.compare(str2) == 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (IsReal() && oper.IsReal())
            {
                ss << GetReal();
                ss >> str1; ss.clear();
                ss << oper.GetReal();
                ss >> str2;
                if (str1.compare(str2) == 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (IsInt() && oper.IsReal())
            {
                ss << GetInt();
                ss >> str1; ss.clear();
                ss << oper.GetReal();
                ss >> str2;
                if (str1.compare(str2) == 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
            else if (IsReal() && oper.IsInt())
            {
                ss << GetReal();
                ss >> str1; ss.clear();
                ss << oper.GetInt();
                ss >> str2;
                if (str1.compare(str2) == 0)
                {
                    return Value(true);
                }
                return Value(false);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    return Value();
}