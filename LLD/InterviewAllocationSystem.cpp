#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stdexcept>
#include <algorithm>
#include <memory>

using namespace std;

// Interview type class
class InterviewType
{
private:
    int id;
    string interviewType;

public:
    InterviewType(int id, const string &type) : id(id), interviewType(type) {}
};

// Time Slot class
class TimeSlot
{
private:
    int id;
    string startTime;
    string endTime;

public:
    TimeSlot(int id, const string &startTime, const string &endTime) : id(id), startTime(startTime), endTime(endTime) {}

    friend class InterviewAllocationSystem;
};

// Users class
class User
{
private:
    int id;
    string name;
    string role;
    unordered_set<int> preferredSlots;
    unordered_set<int> preferredInterviewTypes;

public:
    User(int id, const string &name, const string &role,
         const unordered_set<int> &preferredSlots,
         const unordered_set<int> &preferredInterviewTypes)
        : id(id), name(name), role(role), preferredSlots(preferredSlots), preferredInterviewTypes(preferredInterviewTypes) {}

    friend class InterviewAllocationSystem; // Allowing InterviewAllocationSystem to access private members
};

// InterviewAssignment class
class InterviewAssignment
{
public:
    int interviewerId;
    int intervieweeId;
    int timeSlotId;
    int interviewTypeId;

    InterviewAssignment(int interviewerId, int intervieweeId, int timeSlotId, int interviewTypeId)
        : interviewerId(interviewerId), intervieweeId(intervieweeId), timeSlotId(timeSlotId), interviewTypeId(interviewTypeId) {}
};

// Singleton class for Interview Allocation System
class InterviewAllocationSystem
{
private:
    vector<User> users;
    vector<TimeSlot> timeSlots;
    vector<InterviewType> interviewTypes;
    vector<InterviewAssignment> assignments;

    InterviewAllocationSystem() {}

public:
    static InterviewAllocationSystem &getInstance()
    {
        static InterviewAllocationSystem instance;
        return instance;
    }

    void registerUser(const User &user)
    {
        users.push_back(user);
    }

    void addTimeSlot(const TimeSlot &timeSlot)
    {
        timeSlots.push_back(timeSlot);
    }

    void addInterviewType(const InterviewType &type)
    {
        interviewTypes.push_back(type);
    }

    void allocateInterviews()
    {
        for (auto &interviewee : users)
        {
            string roleLower = interviewee.role;
            transform(roleLower.begin(), roleLower.end(), roleLower.begin(), ::tolower);
            if (roleLower != "interviewee")
                continue;

            for (auto &interviewer : users)
            {
                string roleLower = interviewer.role;
                transform(roleLower.begin(), roleLower.end(), roleLower.begin(), ::tolower);
                if (roleLower != "interviewer")
                    continue;

                unordered_set<int> commonSlots;
                unordered_set<int> commonInterviewTypes;

                for (int slot : interviewee.preferredSlots)
                {
                    if (interviewer.preferredSlots.count(slot))
                    {
                        commonSlots.insert(slot);
                    }
                }

                for (int type : interviewee.preferredInterviewTypes)
                {
                    if (interviewer.preferredInterviewTypes.count(type))
                    {
                        commonInterviewTypes.insert(type);
                    }
                }

                if (!commonSlots.empty() && !commonInterviewTypes.empty())
                {
                    int slot = *commonSlots.begin();
                    int type = *commonInterviewTypes.begin();
                    assignments.emplace_back(interviewer.id, interviewee.id, slot, type);
                    break;
                }
            }
        }
    }

    void handleInvalidSlot(int slotId)
    {
        bool valid = false;
        for (auto &slot : timeSlots)
        {
            if (slot.id == slotId)
            {
                valid = true;
                break;
            }
        }
        if (!valid)
        {
            throw invalid_argument("Invalid slot ID: " + to_string(slotId));
        }
    }

    // Method to print interview assignments
    void printAssignments()
    {
        for (auto &assignment : assignments)
        {
            cout << "Interviewer ID: " << assignment.interviewerId
                 << ", Interviewee ID: " << assignment.intervieweeId
                 << ", Time Slot ID: " << assignment.timeSlotId
                 << ", Interview Type ID: " << assignment.interviewTypeId << endl;
        }
    }

    // Disable copy constructor and assignment operator
    InterviewAllocationSystem(const InterviewAllocationSystem &) = delete;
    InterviewAllocationSystem &operator=(const InterviewAllocationSystem &) = delete;
};

// Main function to demonstrate the usage
int main()
{
    auto &system = InterviewAllocationSystem::getInstance();

    // Add interview types
    system.addInterviewType(InterviewType(1, "Technical"));
    system.addInterviewType(InterviewType(2, "HR"));

    // Add time slots
    system.addTimeSlot(TimeSlot(1, "09:00", "10:00"));
    system.addTimeSlot(TimeSlot(2, "10:00", "11:00"));

    // Register users
    system.registerUser(User(1, "Alice", "Interviewer", {1, 2}, {1}));
    system.registerUser(User(2, "Bob", "Interviewee", {1}, {1, 2}));

    // Allocate interviews
    system.allocateInterviews();

    // Print interview assignments
    system.printAssignments();

    // Handle invalid slot
    try
    {
        system.handleInvalidSlot(9);
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
