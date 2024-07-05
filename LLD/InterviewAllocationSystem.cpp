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
    InterviewType(int id, const string &type) : id(id), interviewType(type) {} // 'type' is not modified

    int getId() const { return id; }                 // Member function doesn't modify the object
    string getType() const { return interviewType; } // Member function doesn't modify the object
};

// Time Slot class
class TimeSlot
{
private:
    int id;
    string startTime;
    string endTime;

public:
    TimeSlot(int id, const string &startTime, const string &endTime) : id(id), startTime(startTime), endTime(endTime) {} // 'startTime' and 'endTime' are not modified

    int getId() const { return id; }                  // Member function doesn't modify the object
    string getStartTime() const { return startTime; } // Member function doesn't modify the object
    string getEndTime() const { return endTime; }     // Member function doesn't modify the object
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
        : id(id), name(name), role(role), preferredSlots(preferredSlots), preferredInterviewTypes(preferredInterviewTypes) {} // Parameters are not modified

    int getId() const { return id; }                                                                 // Member function doesn't modify the object
    string getName() const { return name; }                                                          // Member function doesn't modify the object
    string getRole() const { return role; }                                                          // Member function doesn't modify the object
    const unordered_set<int> &getPreferredSlots() const { return preferredSlots; }                   // Returns a reference that shouldn't be modified
    const unordered_set<int> &getPreferredInterviewTypes() const { return preferredInterviewTypes; } // Returns a reference that shouldn't be modified

    friend class InterviewAllocationSystem; // Allowing InterviewAllocationSystem to access private members
};

// InterviewAssignment class
class InterviewAssignment
{
public:
    int interviewerId;
    int intervieweeId;
    TimeSlot timeSlot;
    InterviewType interviewType;

    InterviewAssignment(int interviewerId, int intervieweeId, const TimeSlot &timeSlot, const InterviewType &interviewType)
        : interviewerId(interviewerId), intervieweeId(intervieweeId), timeSlot(timeSlot), interviewType(interviewType) {} // Parameters are not modified
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
        users.push_back(user); // 'user' is not modified
    }

    void addTimeSlot(const TimeSlot &timeSlot)
    {
        timeSlots.push_back(timeSlot); // 'timeSlot' is not modified
    }

    void addInterviewType(const InterviewType &type)
    {
        interviewTypes.push_back(type); // 'type' is not modified
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
                    int slotId = *commonSlots.begin();
                    int typeId = *commonInterviewTypes.begin();

                    TimeSlot selectedSlot(0, "", "");
                    for (const auto &slot : timeSlots)
                    {
                        if (slot.getId() == slotId)
                        {
                            selectedSlot = slot;
                            break;
                        }
                    }

                    InterviewType selectedType(0, "");
                    for (const auto &type : interviewTypes)
                    {
                        if (type.getId() == typeId)
                        {
                            selectedType = type;
                            break;
                        }
                    }

                    assignments.emplace_back(interviewer.getId(), interviewee.getId(), selectedSlot, selectedType);
                    break;
                }
            }
        }
    }

    // Method to print interview assignments
    void printAssignments() const
    { // Member function doesn't modify the object
        for (const auto &assignment : assignments)
        {
            cout << "Interviewer ID: " << assignment.interviewerId
                 << ", Interviewee ID: " << assignment.intervieweeId
                 << ", Time Slot: " << assignment.timeSlot.getStartTime() << " to " << assignment.timeSlot.getEndTime()
                 << ", Interview Type: " << assignment.interviewType.getType() << endl;
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

    return 0;
}
