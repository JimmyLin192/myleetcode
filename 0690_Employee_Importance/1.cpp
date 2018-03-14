/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> lookup;
        for (auto emp : employees) {
            lookup[emp->id] = emp; 
        }
        return getImportanceHelper(lookup, id);
    }
    int getImportanceHelper(unordered_map<int, Employee*>& lookup, int id) {
        int ans = 0;
        if (lookup.find(id) == lookup.end()) {
            return ans;
        }
        ans += lookup[id]->importance;
        for (int sub_id : lookup[id]->subordinates) {
            ans += getImportanceHelper(lookup, sub_id);
        }
        return ans;
    }
};
