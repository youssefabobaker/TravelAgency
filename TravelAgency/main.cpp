#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include<Windows.h>
#include<ctime>
using namespace std;
class log_in
{
private:
    string username;
    string password;
public:
    void set_username(string user)
    {
        username = user;
    }
    void set_password(string pass)
    {
        password = pass;
    }
};
class sign_up : public log_in
{
private:
    string firstname;
    string lastname;
    string address;
    string phonenumber;
    int age;
    string username;
    string password;
public:
    void set_firstname(string fname)
    {
        firstname = fname;
    }
    void set_lastname(string lname)
    {
        lastname = lname;
    }
    void set_address(string add)
    {
        address = add;
    }
    void set_phonenumber(string pnumber)
    {
        phonenumber = pnumber;
    }
    void set_age(int ag)
    {
        age = ag;
    }
    void set_username(string user)
    {
        username = user;
    }
    void set_password(string pass)
    {
        password = pass;
    }
};
class destination {
private:
    string startingpoint;
    string destination;
    string hotel = "no hotel";
    int number_of_night;
public: void set_destination(string x)
    {
        destination = x;
    }
    void set_startingpoint(string y)
    {
        startingpoint = y;
    }
    void set_hotel(string z)
    {
        hotel = z;
    }
    void set_nights(int n)
    {
        number_of_night = n;
    }
    string get_destination()
    {
        return destination;
    }
    string get_startingpoint()
    {
        return startingpoint;
    }
    string get_hotelname() {
        return hotel;
    }
};
class CreditCard {
private:
    string CCNumber, CCDate, CCName;
public:
    void set_CCName(string s1)
    {
        CCName = s1;
    }
    void set_CCDate(string s2)
    {
        CCDate = s2;
    }
    void set_CCNumber(string s3)
    {
        CCNumber = s3;
    }
};


int main()

{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 2);
    srand(time(0));
    cout << "--------------------------------HELLO---------------------------\n";
    cout << "-----------------------WElCOM TO OUR TRAVELING APP---------------------\n";
    cout << "-------------------------------LOG-IN MENU-----------------------------\n";
    float Price = 0.0;
    char regist;
    string name, pass;

    cout << "choose:\n1:log in \n2:sign up\n0:quite\n";
    cin >> regist;
    system("cls");
    if (regist == '2') {
        x:
        sign_up user;
        string firstname, lastname, address, phone_number, username, password;
        int age;
        cout << "please enter your first name: ";
        cin >> firstname;
        user.set_firstname(firstname);
        cout << "please enter your last name: ";
        cin >> lastname;
        user.set_lastname(lastname);
        cout << "please enter your address: ";
        cin.ignore(1, '\n');
        getline(cin, address);
        user.set_address(address);
        cout << "please enter your phone number: ";
        cin >> phone_number;
        user.set_phonenumber(phone_number);
        cout << "please enter your age: ";
        cin >> age;
        if (age < 18) {
            cout << "Sorry you can't Signup" << endl;
            return 1;
        }
        user.set_age(age);
        cout << "please enter a username: ";
        cin >> username;
        user.set_username(username);
        do {
            cout << "please enter a password min 8 characters: ";
            cin >> password;
        } while (password.length() < 8);

        user.set_password(password);
        ofstream Data;
        Data.open("D://accounts.txt", ios::app);
        if (Data.is_open()) {
            Data << username << "\n";
            Data << password << "\n";
            Data.close();
        }system("cls");
        cout << "\t\tRegistration is successful!!\n";
    }
    else if (regist == '1') {
        log_in user;
        string username, password, name, pass;
        int counter = 0;
        int counter1 = 0;
        int x;
        do {
            cout << "please enter the username :";
            cin >> username;
            user.set_username(username);
            cout << "please enter the password :";
            cin >> password;
            user.set_password(password);
            ifstream login("records.txt");
            while (login >> name >> pass)
            {
                if ((name == username) && (pass == password))
                {
                    counter = 1;
                }
            }
            login.close();
            if (counter == 1) {
                system("cls");
                cout << username << "\nYOUR LOGIN IS SUCCESSFUL\n";
            }
            else {
                cout << username << "\nLOGIN ERROR\nPLEASE CHECK YOUR USERNAME AND PASSWORD\n ";
                counter1++;
                if (counter1 == 4)
                {
                    cout << "IF YOU DONT HAVE A USERNAME YOU CAN SIGNUP OR QUITE\n";
                    cout << "1:signup\n2:quite\n";
                    y:
                    cin >> x;
                    if (x == 1) {
                        goto x;

                    }
                    if (x == 2) {
                        cout << "THANK YOU BYE BYE!!\n";
                        return 0;
                    }
                    if (x != 1 && x != 2)
                        cout << "PLEASE CHOOSE A CORRECT NUMBER\n";
                    goto x;
                }
            }
        } while (counter != 1);
    }
    else {
        cout << "Thank You Bye Bye\n";
        return 0;
    }
    SetConsoleTextAttribute(h, 4);
    cout << "-------------------------------------------------------------------------------------\n";
    cout << "-----------------------------------DESTINATION SECTION-------------------------------\n";
    destination trip;
    string current_station, destination, hotel_name = "No Hotel";
    char x, y;
    cout << "please enter your current station: " << "\n";
    cin.ignore(1, '\n');
    getline(cin, current_station);
    trip.set_startingpoint(current_station);
    cout
            << "Please Choose Your destination from the options\n1:Sharm El-Sheikh  Price: Airplane=500$.....Bus=200$   \n2:Aswan  Price: Airplane=700$.....Bus=300$ \n3:Luxor Price: Airplane=600$.....Bus=250$ \n4:Hurghada  Price: Airplane=450$.....Bus=170$ \n5:Alexandria  Price: Airplane=250$.....Bus=75$ \n6:Dahab  Price: Airplane=570$.....Bus=275$ \n0:quite\n";

    do {
        cin >> x;
        if ((x != '0') && (x != '1') && (x != '2') && (x != '3') && (x != '4') && (x != '5') && (x != '6')){
            cout << "Please Choose from the Previous options\n";
        }
    } while ((x != '0') && (x != '1') && (x != '2') && (x != '3') && (x != '4') && (x != '5') && (x != '6'));
    switch (x) {
        case '0': {
            cout << "Thank YOU BYE BYE\n";
            return 0;

        }
        case '1': {
            destination = "SharmEL-sheikh";
            break;
        }
        case '2': {
            destination = "Aswan";
            break;
        }
        case '3': {
            destination = "Luxor";
            break;
        }
        case '4': {
            destination = "Hurghada";
            break;
        }
        case '5': {
            destination = "Alexandria";
            break;
        }
        case '6': {
            destination = "Dahab";
            break;
        }
        default: {
            cout << "Please Choose from the Following options\n";
        }
    }
    // system("cls");
    cout << "Your trip is From " << current_station << " To " << destination << endl;
    cout << "\n1:to Choose the hotel\n2:if you don't need hotel\n0:quite\n";
    char z, p = 0, nights = 0;
    float hotel_price = 0.0;
    do {
        cin >> y;
        if ((y != '0') && (y != '1') && (y != '2')) {
            cout << "Please Choose from the Previous options\n ";
        }
        //system("cls");
    } while ((y != '0') && (y != '1') && (y != '2') );
    if (y == '0') {
        cout << "THANK YOU BYE BYE\n";
        return 0;
    }
    if (y == '1') {
        if (destination == "SharmEL-sheikh") {
            cout
                    << "\n1:Hollywood Sharm El-sheikh Hotel\t$330 per night\n2:Palma Di Sharm Hotel\t$280 per night\n3:Porto Sharm Hotel\t$210 per night\n";
            do {
                cin >> z;
                if (((z != '1') && (z != '2') && (z != '3'))) {
                    cout << "Please Choose from the Previous options\n ";
                }
            } while ((z != '1') && (z != '2') && (z != '3'));
            switch (z) {
                case '1': {
                    hotel_name = "Hollywood Sharm El-sheikh Hotel";
                    p = 330;
                    break;
                }
                case '2': {
                    hotel_name = "Palma Di Sharm Hotel";
                    p = 280;
                    break;
                }
                case '3': {
                    hotel_name = "Porto Sharm Hotel";
                    p = 210;
                    break;
                }
                default: {
                    cout << "Please Choose from the Following options\n";
                }
            }
        }
        else if (destination == "Aswan") {
            cout
                    << "\n1:Citymax Hotel\t$310 per night\n2:Pyramisa Island Hotel\t$250 per night\n3:Kato Dool Nubian Hotel\t$100 per night\n";
            do {
                cin >> z;
                if (((z != '1') && (z != '2') && (z != '3'))) {
                    cout << "Please Choose from the Previous options\n ";
                }
            } while ((z != '1') && (z != '2') && (z != '3'));
            switch (z) {
                case '1': {
                    hotel_name = "Citymax Hotel";
                    p = 310;
                    break;
                }
                case '2': {
                    hotel_name = "Pyramisa Island Hotel";
                    p = 250;
                    break;
                }
                case '3': {
                    hotel_name = "Kato Dool Nubian Hotel";
                    p = 100;
                    break;
                }
                default: {
                    cout << "Please Choose from the Following options\n";
                }
            }
        }
        else if (destination == "Luxor") {
            cout
                    << "\n1:Nefertiti Hotel\t$300 per night\n2:Pyramisa Hotel\t$210 per night\n3:Susanna Hotel\t$150 per night\n";
            do {
                cin >> z;
                if (((z != '1') && (z != '2') && (z != '3'))) {
                    cout << "Please Choose from the Previous options\n ";
                }
            } while ((z != '1') && (z != '2') && (z != '3'));
            switch (z) {
                case '1': {
                    hotel_name = "Nefertiti Hotel";
                    p = 300;
                    break;
                }
                case '2': {
                    hotel_name = "Pyramisa Hotel";
                    p = 210;
                    break;
                }
                case '3': {
                    hotel_name = "Susanna Hotel";
                    p = 150;
                    break;
                }
                default: {
                    cout << "Please Choose from the Following options\n";
                }
            }
        }
        else if (destination == "Hurghada") {
            cout
                    << "\n1:Hilton Hurghada Plaza Hotel\t$350 per night\n2:Royal City Hotel\t$270 per night\n3:Sky View Suits Hotel\t$200 per night\n";
            do {
                cin >> z;
                if (((z != '1') && (z != '2') && (z != '3'))) {
                    cout << "Please Choose from the Previous options\n ";
                }
            } while ((z != '1') && (z != '2') && (z != '3'));
            switch (z) {
                case '1': {
                    hotel_name = "Hilton Hurghada Plaza Hotel";
                    p = 350;
                    break;
                }
                case '2': {
                    hotel_name = "Royal City Hotel";
                    p = 270;
                    break;
                }
                case '3': {
                    hotel_name = "Sky View Suits Hotel";
                    p = 200;
                    break;
                }
                default: {
                    cout << "Please Choose from the Following options\n";
                }
            }
        }
        else if (destination == "Alexandria") {
            cout << "\n1:Tolip Hotel\t$200 per night\n2:Plaza Hotel\t$190 per night\n3:Amoun Hotel\t$150 per night\n";
            do {
                cin >> z;
                if (((z != '1') && (z != '2') && (z != '3'))) {
                    cout << "Please Choose from the Previous options\n ";
                }
            } while ((z != '1') && (z != '2') && (z != '3'));
            switch (z) {
                case '1': {
                    hotel_name = "Tolip Hotel";
                    p = 200;
                    break;
                }
                case '2': {
                    hotel_name = "Plaza Hotel";
                    p = 190;
                    break;
                }
                case '3': {
                    hotel_name = "Amoun Hotel";
                    p = 150;
                    break;
                }
                default: {
                    cout << "Please Choose from the Following options\n";
                }
            }
        }
        else if (destination == "Dahab") {
            cout
                    << "\n1:Seaview Hotel\t$330 per night\n2:El Primo Hotel\t$270 per night\n3:Carmine Hotel\t$230 per night\n";
            do {
                cin >> z;
                if (((z != '1') && (z != '2') && (z != '3'))) {
                    cout << "Please Choose from the Previous options\n ";
                }
            } while ((z != '1') && (z != '2') && (z != '3'));
            switch (z) {
                case '1': {
                    hotel_name = "Seaview Hotel";
                    p = 330;
                    break;
                }
                case '2': {
                    hotel_name = "El Primo Hotel";
                    p = 270;
                    break;
                }
                case '3': {
                    hotel_name = "Carmine Hotel";
                    p = 230;
                    break;
                }
                default: {
                    cout << "Please Choose from the Following options\n";
                }
            }
        }
        cout << "\nplease enter the number of night\n";
        cin >> nights;
    }
    hotel_price = nights * p;
    trip.set_nights(nights);
    trip.set_destination(destination);
    trip.set_hotel(hotel_name);
    ofstream information;
    information.open("D://information of trip.txt", ios::out);
    {
        information << current_station << "\n";
        information << destination << "\n";
        information << hotel_name << "\n";
        information << nights << "\n";
    }
    information.close();
    ofstream date_trip;
    int day, month;
    date_trip.open("date of trip.txt", ios::app);
    cout << "please enter the date of your trip ";
    cout << "\nThe day: ";
    do {
        cin >> day;
        if ((day < 0) || (day > 31))
            cout << "wrong format,Please reEnter the day\n";
    } while ((day < 0) || (day > 31));


    cout << "the month: ";
    do {
        cin >> month;
        if ((month < 0) || (month > 12))
            cout << "wrong format,Please reEnter the day\n";
    } while ((month < 0) || (month > 12));

    system("cls");
    date_trip << "the date of trip: " << day << "/" << month;
    date_trip.close();
    SetConsoleTextAttribute(h, 3);
    cout << "-------------------------------------------------------------------------------------\n";
    cout << "---------------------------------TRANSPORTATION SECTION------------------------------\n";
    char T;
    string transportation;
    cout << "Please Choose Your type of transportation\n1:Airplane\n2:Bus\n0:quite\n";
    do {
        cin >> T;
        if (T != '1' && T != '2' && T != '0')
            cout << "please choose from the previous options\n";
    } while (T != '1' && T != '2' && T != '0');
    if (T == '1') {
        transportation = "Airplane";
    }
    if (T == '2') {
        transportation = "Bus";
    }
    if (T == '0') {
        cout << "THANK YOU BYE BYE\n";
        return 0;
    }
    ofstream type_travelinormation, class_typeinformation;
    char C;
    char L;
    string Type_Travel;
    string Class_Type;
    class_typeinformation.open("D://class details", ios::app);
    cout << "Please choose your seat class in the " << transportation << "\n1:A\n2:B\n3:C\n";
    do {
        cin >> C;
        if (!((C == '1') || (C == '2') || (C == '3')))
            cout << "please choose from the Previous options\n";
    } while (!((C == '1') || (C == '2') || (C == '3')));
    if (C == '1')
        Class_Type = 'A';
    else if (C == '2')
        Class_Type = 'B';
    else if (C == '3')
        Class_Type = 'C';
    class_typeinformation << Class_Type;
    class_typeinformation.close();
    type_travelinormation.open("D://Type of travel details.txt ", ios::app);
    cout << "Please Choose Your Type of Traveling\n1:One-Way\n2:Round Trip (Extra 50% discount of price)\n";
    do {
        cin >> L;
        if (L != '1' && L != '2')
            cout << "please choose from the Previous options\n";
    } while (L != '1' && L != '2');
    if (L == '1') {
        Type_Travel = "One-Way";
    }
    else if (L == '2') {
        Type_Travel = "Round Trip";
    }
    type_travelinormation << Type_Travel;
    type_travelinormation.close();
    //price list
    ofstream price_details;
    int sharmAir = 500, sharmBus = 200, aswanAir = 700, aswanBus = 300, luxorAir = 600, luxorBus = 250;
    int hurghadaAir = 450, hurghadaBus = 170, alexAir = 250, alexBus = 75, dahabAir = 570, dahabBus = 275;
    price_details.open("price information.txt", ios::out);
    if (destination == "SharmEL-sheikh") {
        if (transportation == "Airplane") {
            Price = sharmAir;
        }
        else if (transportation == "Bus") {
            Price = sharmBus;
        }
    }
    else if (destination == "Aswan") {
        if (transportation == "Airplane") {
            Price = aswanAir;
        }
        else if (transportation == "Bus") {
            Price = aswanBus;
        }
    }
    else if (destination == "Luxor") {
        if (transportation == "Airplane") {
            Price = luxorAir;
        }
        else if (transportation == "Bus") {
            Price = luxorBus;
        }
    }
    else if (destination == "Dahab") {
        if (transportation == "Airplane") {
            Price = dahabAir;
        }
        else if (transportation == "Bus") {
            Price = dahabBus;
        }
    }
    else if (destination == "Alexandria") {
        if (transportation == "Airplane") {
            Price = alexAir;
        }
        else if (transportation == "Bus") {
            Price = alexBus;
        }
    }
    else if (destination == "Hurghada") {
        if (transportation == "Airplane") {
            Price = hurghadaAir;
        }
        else if (transportation == "Bus") {
            Price = hurghadaBus;
        }
    }
    price_details << "your destination is " << destination << " and your transportaion is " << transportation << "\n";
    price_details << " the price of transportaion " << Price;
    price_details << "the hotel price " << hotel_price << "for " << nights;
    price_details << "the total price " << Price << "$" << endl;
    price_details.close();
    system("cls");
    SetConsoleTextAttribute(h, 5);
    cout << "-------------------------------------------------------------------------------------\n";
    cout << "-------------------------------------Trip Details-----------------------------------\n";
    cout << "From: " << current_station << " \nTo :" << destination << "\nDate of reservation is "<<day<<"/"<<month<<"\n" << "\nthe hotel is " << trip.get_hotelname() << "\nthe number of night in hotel is " << nights <<
         " \nTransportation: " << transportation << " \nClass: " << Class_Type << " Class"
                                                                                  " \nTravel Type: " << Type_Travel;
    if (Type_Travel == "Round Trip")
    {
        Price = Price * 2;
        cout << "\nPrice for transportation before Discount = " << Price << "$";
        Price = Price * 0.75;
        cout << "\nprice for transportation After Discount = " << Price << "$" << endl;
    }
    else
    {
        cout << "\nTotal Price For Transportation= " << Price << "$" << endl;
    }
    cout << "\nTotal price for hotel is " << hotel_price << "$" << endl;
    cout << "\ntotal price for transportation is " << Price;
    cout << "\nTHE TOTAL PRICE FOR ALL TRIP IS " << Price + hotel_price << "$" << endl;
    cout << "\nChoose a method of payment:\n1:Credit Card\n2:Fawry\n0:quite\n";
    int choice;
    do {
        cin >> choice;
        if (!(choice >= 0 && choice < 3))
            cout << "please choose from the priveous options\n";
    } while (!(choice >= 0 && choice < 3));
    if (choice == 1) {
        string CCnumber, CCname, CCdate;
        CreditCard CC;
        cout << "\nenter the 14 numbers on your card: ";
        do {
            cin >> CCnumber;
            if (CCnumber.length() != 14)
            {
                cout << "\nWrong Format, Please Re-Enter: ";
            }
        } while (CCnumber.length() != 14);
        CC.set_CCNumber(CCnumber);
        ofstream write("D://CreditCard.txt");
        write << CCnumber;
        cout << "\nenter the expiration date on your card: ";
        cin.ignore(1, '\n');
        getline(cin, CCdate);
        CC.set_CCDate(CCdate);
        write << CCdate;
        cout << "\nenter the name on your card ";
        cin.ignore(1, '\n');
        getline(cin, CCname);
        CC.set_CCName(CCname);
        write << CCname;
        write.close();
        cout << "\nyour payment is done and your card details have been saved for the next reservation";
    }
    else if (choice == 2)
    {
        cout << "your payment code is: ";
        for (int i = 0; i < 10; i++) {
            int num = rand()%10;
            cout << num;
        }
    }
    else if (choice == 0) {
        cout << "THANK YOU BYE BYE\n";
        return 0;
    }
    cout << "\n-------------------------------------------------------------------------------------\n";
    cout << "\n----------------------------------THANK YOU BYE BYE:)---------------------------------\n";
}