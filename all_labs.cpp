#include <iostream>
#include <string>
using namespace std;


class OTT {
private:
    string name;
    float price;
public:
    void getdata() {
        cout << "Enter OTT platform Name (Netflix/Prime/Hotstar): ";
        cin >> name;
        if (name == "Netflix") {
            price = 399;
        } else if (name == "Prime") {
            price = 299;
        } else if (name == "Hotstar") {
            price = 199;
        } else {
            price = 0;
        }
        cout << "Price = " << price << endl;
    }
    void showdata() {
        cout << "\nYour Platform is: " << name << endl;
        if (price == 0)
            cout << "Invalid platform" << endl;
    }
};


void addFoodDonation(string donorName, int foodQuantity, string expiryTime = "4 hours") {
    cout << "\nDonor Name: " << donorName;
    cout << "\nFood Quantity (in packets): " << foodQuantity;
    cout << "\nExpiry Time: " << expiryTime << endl;
}


class FoodDonation3 {
private:
    string donorName;
    int foodPackets;
public:
    void setDetails(string name, int packets) {
        donorName = name;
        foodPackets = packets;
    }
    friend void displayDonation(FoodDonation3 fd);
};
void displayDonation(FoodDonation3 fd) {
    cout << "Donor Name: " << fd.donorName << endl;
    cout << "Number of Food Packets Donated: " << fd.foodPackets << endl;
}


class FoodDonation4 {
private:
    string donorName;
    int foodPackets;
    string location;
public:
    FoodDonation4() {
        donorName = "Unknown Donor";
        foodPackets = 0;
        location = "Not specified";
    }
    FoodDonation4(string name, int packets, string loc) {
        donorName = name;
        foodPackets = packets;
        location = loc;
    }
    void displayDonation() {
        cout << "\nDonor Name     : " << donorName;
        cout << "\nFood Packets   : " << foodPackets;
        cout << "\nLocation       : " << location << endl;
    }
};


class FoodDonation5 {
private:
    int packets;
    static int totalPackets;
public:
    FoodDonation5(int p = 0) {
        packets = p;
        totalPackets += p;
    }
    static void displayTotal() {
        cout << "Total leftover food packets collected: " << totalPackets << endl;
    }
    void display() {
        cout << "This donor gave: " << packets << " packets" << endl;
    }
};
int FoodDonation5::totalPackets = 0;


class FoodDonation6 {
public:
    void displayDonation(string donorName) {
        cout << "\nDonor Name: " << donorName << endl;
    }
    void displayDonation(string donorName, string foodType) {
        cout << "\nDonor Name: " << donorName << ", Food Type: " << foodType << endl;
    }
    void displayDonation(string donorName, string foodType, int packets) {
        cout << "\nDonor Name: " << donorName << ", Food Type: " << foodType << ", Packets: " << packets << endl;
    }
};


class FoodDonation7 {
private:
    int packets;
public:
    FoodDonation7(int p = 0) {
        packets = p;
    }
    void operator++() { ++packets; }
    void operator--() { --packets; }
    void display() {
        cout << "Total Food Packets: " << packets << endl;
    }
};


class FoodDonation8 {
private:
    int packets;
public:
    FoodDonation8(int p = 0) {
        packets = p;
    }
    FoodDonation8 operator+(FoodDonation8 obj) {
        FoodDonation8 temp;
        temp.packets = this->packets + obj.packets;
        return temp;
    }
    void getInput() {
        cout << "Enter number of leftover food packets: ";
        cin >> packets;
    }
    void display() {
        cout << "Total food packets: " << packets << endl;
    }
};


class FoodDonation9 {
protected:
    int packets;
public:
    void getPackets() {
        cout << "Enter number of leftover food packets donated: ";
        cin >> packets;
    }
};
class Donor9 : public FoodDonation9 {
protected:
    string donorName;
public:
    void getDonorDetails() {
        cout << "Enter donor name: ";
        cin >> donorName;
    }
};
class Distribution9 : public Donor9 {
private:
    string location;
public:
    void getLocation() {
        cout << "Enter distribution location: ";
        cin >> location;
    }
    void displayDetails() {
        cout << "\n--- Food Donation Details ---\n";
        cout << "Donor Name: " << donorName << endl;
        cout << "Packets Donated: " << packets << endl;
        cout << "Distributed At: " << location << endl;
    }
};


class Donor10 {
protected:
    string donorName;
public:
    void getDonor() {
        cout << "Enter Donor Name: ";
        cin >> donorName;
    }
    void showDonor() {
        cout << "Donor Name: " << donorName << endl;
    }
};
class FoodDetails10 {
protected:
    int packets;
public:
    void getFood() {
        cout << "Enter number of leftover food packets: ";
        cin >> packets;
    }
    void showFood() {
        cout << "Food Packets Donated: " << packets << endl;
    }
};
class FoodDonation10 : public Donor10, public FoodDetails10 {
public:
    void getData() {
        getDonor();
        getFood();
    }
    void showDonation() {
        cout << "\n- Donation Details -" << endl;
        showDonor();
        showFood();
    }
};


int main() {
    int choice;
    do {
        cout << "\n====== MENU ======";
        cout << "\n1. Lab 1 - Classes and objects";
        cout << "\n2. Lab 2 - Default argument";
        cout << "\n3. Lab 3 - Friend Function";
        cout << "\n4. Lab 4 - default and parameterized constructor";
        cout << "\n5. Lab 5 - Static functions";
        cout << "\n6. Lab 6 - Function Overloading";
        cout << "\n7. Lab 7 - Unary Operator Overloading";
        cout << "\n8. Lab 8 - Binary Operator Overloading ";
        cout << "\n9. Lab 9 - Multi level Inheritance ";
        cout << "\n10. Lab 10 - Multiple Inheritance";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        cin.ignore(); // clear buffer

        switch (choice) {
        case 1: {
            OTT p1;
            p1.getdata();
            p1.showdata();
            break;
        }
        case 2: {
            addFoodDonation("FoodPoint Restaurant", 50, "2 hours");
            addFoodDonation("EventX", 30);
            break;
        }
        case 3: {
            FoodDonation3 fd1;
            fd1.setDetails("Hotel Green Bowl", 25);
            displayDonation(fd1);
            break;
        }
        case 4: {
            string name, loc;
            int packets;
            cout << "Enter Food Donation Details\n";
            cout << "Donor Name: ";
            getline(cin, name);
            cout << "Number of Food Packets: ";
            cin >> packets;
            cin.ignore();
            cout << "Location: ";
            getline(cin, loc);
            FoodDonation4 userDonation(name, packets, loc);
            userDonation.displayDonation();
            break;
        }
        case 5: {
            int n, p;
            cout << "Enter number of donors: ";
            cin >> n;
            for (int i = 1; i <= n; i++) {
                cout << "Enter leftover packets donated by donor " << i << ": ";
                cin >> p;
                FoodDonation5 donor(p);
                donor.display();
            }
            FoodDonation5::displayTotal();
            break;
        }
        case 6: {
            FoodDonation6 fd;
            string name, food;
            int packets;
            cout << "Enter Donor Name: ";
            getline(cin, name);
            cout << "Enter Food Type: ";
            getline(cin, food);
            cout << "Enter Number of Packets: ";
            cin >> packets;
            cout << "\nDonation Details\n";
            fd.displayDonation(name);
            fd.displayDonation(name, food);
            fd.displayDonation(name, food, packets);
            break;
        }
        case 7: {
            int initialPackets;
            cout << "Enter initial number of food packets: ";
            cin >> initialPackets;
            FoodDonation7 fd(initialPackets);
            cout << "\nInitial Donation: ";
            fd.display();
            ++fd;
            cout << "After Increment (++): ";
            fd.display();
            --fd;
            cout << "After Decrement (--): ";
            fd.display();
            break;
        }
        case 8: {
            FoodDonation8 center1, center2, total;
            cout << "Food Center 1:\n";
            center1.getInput();
            cout << "\nFood Center 2:\n";
            center2.getInput();
            total = center1 + center2;
            cout << "\n--- Combined Donation ---\n";
            total.display();
            break;
        }
        case 9: {
            Distribution9 obj;
            obj.getDonorDetails();
            obj.getPackets();
            obj.getLocation();
            obj.displayDetails();
            break;
        }
        case 10: {
            FoodDonation10 d1, d2;
            cout << "\nEnter details of Donor 1:\n";
            d1.getData();
            cout << "\nEnter details of Donor 2:\n";
            d2.getData();
            cout << "\n- All Donations -\n";
            d1.showDonation();
            d2.showDonation();
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

