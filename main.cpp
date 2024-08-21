#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class to represent a person
class Person {
protected:
    string name;
    int age;
    string gender;

public:
    Person() {}

    void inputDetails() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter gender: ";
        cin.ignore();
        getline(cin, gender);
    }

    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

// Class to represent a patient
class Patient : public Person {
    int patientID;
    string disease;

public:
    Patient() {}

    void inputDetails() {
        cout << "Enter Patient ID: ";
        cin >> patientID;
        cin.ignore();
        Person::inputDetails();
        cout << "Enter disease: ";
        getline(cin, disease);
    }

    void displayDetails() const {
        cout << "Patient ID: " << patientID << endl;
        Person::displayDetails();
        cout << "Disease: " << disease << endl;
    }
};

// Class to represent a doctor
class Doctor : public Person {
    int doctorID;
    string specialization;

public:
    Doctor() {}

    void inputDetails() {
        cout << "Enter Doctor ID: ";
        cin >> doctorID;
        cin.ignore();
        Person::inputDetails();
        cout << "Enter specialization: ";
        getline(cin, specialization);
    }

    void displayDetails() const {
        cout << "Doctor ID: " << doctorID << endl;
        Person::displayDetails();
        cout << "Specialization: " << specialization << endl;
    }
};

// Class to represent an appointment
class Appointment {
    int appointmentID;
    Patient patient;
    Doctor doctor;
    string date;

public:
    Appointment() {}

    void inputDetails() {
        cout << "Enter Appointment ID: ";
        cin >> appointmentID;
        cin.ignore();

        cout << "\nEnter Patient Details:" << endl;
        patient.inputDetails();

        cout << "\nEnter Doctor Details:" << endl;
        doctor.inputDetails();

        cout << "Enter appointment date (YYYY-MM-DD): ";
        getline(cin, date);
    }

    void displayDetails() const {
        cout << "Appointment ID: " << appointmentID << endl;
        cout << "Date: " << date << endl;
        cout << "\nPatient Details:" << endl;
        patient.displayDetails();
        cout << "\nDoctor Details:" << endl;
        doctor.displayDetails();
    }
};

// Main function to demonstrate the Hospital Management System
int main() {
    Appointment appointment;

    cout << "Hospital Management System" << endl;
    cout << "==========================" << endl;

    appointment.inputDetails();

    cout << "\nAppointment Details:" << endl;
    appointment.displayDetails();

    return 0;
}
