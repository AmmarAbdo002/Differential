#include <iostream>
#include <cmath>
using namespace std;

void TaylorSeries();
void EulerMethod();
void Rung_KuttaMethod();

int main()
{
    float value = 0;
    value = (13.0 / 6.0);
    cout << value << endl;
    int n = 0;
    do
    {
    her:
        cout << "1- To Taylor series" << endl;
        cout << "2- To Euler method" << endl;
        cout << "3- To Rung_Kutta method" << endl;
        cout << "4- To Exit" << endl;
        cout << "Enter the number you choose : ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "\n--------------------------------------------------------\n";
            TaylorSeries();
            cout << "\n\n";
            break;
        case 2:
            cout << "\n--------------------------------------------------------\n";
            EulerMethod();
            cout << "\n\n";
            break;
        case 3:
            cout << "\n\n";
            Rung_KuttaMethod();
            cout << "\n\n";
            break;
        case 4:
            break;
        default:
            cout << "\n--------------------------------------------------------\n";
            cout << "Error! --> chose avalid number" << endl;
            cout << "\n\n";
            goto her;
        }
    } while (n != 4);

    return 0;
}

double setData(string str)
{
    double value;
    cout << str;
    cin >> value;
    return value;
}

int factorial(int num)
{
    if (num == 1 || num == 0)
        return 1;

    else
        return num * factorial(num - 1);
}
void TaylorSeries()
{
    cout << "<< Enter your Equation (y`) >>" << endl;
    double p_x = setData("parameter X :");
    double pow_x = setData("power X :");
    double p_y = setData("parameter y :");
    double pow_y = setData("power y:");
    cout << endl;

    double h = setData("Enter The began step (h) :");
    cout << endl;

    cout << "<< Enter the initial point ( y(xo)=y ) >>" << endl;
    double x = setData("Xo :");
    double y = setData("Yo :");
    cout << endl;

    int numberOfSteps = setData("Enter number fo steps :");
    cout << endl;

    for (int i = 0; i < numberOfSteps; i++)
    {
        double dY = (p_x * pow(x, pow_x)) + (p_y * pow(y, pow_y));

        double ddY, dddY = ddY = (pow_x * pow(x, pow_x - 1)) + dY;
        y = y + (h * dY) +
            ((pow(h, 2) / factorial(2)) * ddY) +
            ((pow(h, 3) / factorial(3)) * dddY);
        x += h;



        cout << endl
             << "y(" << x << ") = " << y << endl;
             
        for (int i = 0; i < pow(10, 8); i++)
        {
        }     
    }
}

void EulerMethod()
{
    cout << "<< Enter your Equation (y`) >>" << endl;
    double p_x = setData("parameter X :");
    double pow_x = setData("power X :");
    double p_y = setData("parameter y :");
    double pow_y = setData("power y:");
    cout << endl;

    double h = setData("Enter The began step (h) :");
    cout << endl;

    cout << "<< Enter the initial point ( y(xo)=y ) >>" << endl;
    float x = setData("Xo :");
    double y = setData("Yo :");
    cout << endl;

    float final_x = setData("You want compute y at --> x = ");
    cout << endl;

    while (x != final_x)
    {
        double dy = (p_x * pow(x, pow_x)) + (p_y * pow(y, pow_y));
        y = y + h * dy;
        x += h;
    }

    cout << endl;
    cout << "y(" << final_x << ") = " << y;
    for (int i = 0; i < pow(10, 8) * .5; i++)
    {
    }
}

void Rung_KuttaMethod()
{
    cout << "<< Enter your Equation (y`) >>" << endl;
    double p_x = setData("parameter X :");
    double pow_x = setData("power X :");
    double p_y = setData("parameter y :");
    double pow_y = setData("power y:");
    cout << endl;

    double h = setData("Enter The began step (h) :");
    cout << endl;

    cout << "<< Enter the initial point ( y(xo)=y ) >>" << endl;
    double x = setData("Xo :");
    double y = setData("Yo :");
    cout << endl;

    float final_x = setData("You want compute y at --> x = ");
    cout << endl
         << endl;
    float temp = x;
    while (temp != final_x)
    {
        temp += h;
        double dy;
        double X = x, Y = y;

        dy = ((p_x * pow(X, pow_x)) + (p_y * pow(Y, pow_y)));
        double k1 = h * dy;

        X = x + (h / 2.0);
        Y = y + (k1 / 2.0);
        dy = ((p_x * pow(X, pow_x)) + (p_y * pow(Y, pow_y)));
        double k2 = h * dy;

        Y = y + (k2 / 2.0);
        dy = ((p_x * pow(X, pow_x)) + (p_y * pow(Y, pow_y)));
        double k3 = h * dy;

        X = x + h;
        Y = y + k3;
        dy = ((p_x * pow(X, pow_x)) + (p_y * pow(Y, pow_y)));
        double k4 = h * dy;

        // cout<<"K1 = "<<k1<<endl;
        // cout<<"K2 = "<<k2<<endl;
        // cout<<"K3 = "<<k3<<endl;
        // cout<<"K4 = "<<k4<<endl<<endl;

        y = y + ((1.0 / 6.0) * (k1 + (2 * k2) + (2 * k3) + k4));

        cout << "y(" << temp << ") = " << y << endl;
        for (int i; i < pow(10, 8) * .5; i++)
        {
        }
    }
}