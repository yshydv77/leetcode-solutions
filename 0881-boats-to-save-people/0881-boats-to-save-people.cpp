class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    int i = 0;
    int j = people.size()-1;
    int count = 0;
    while (i < j)
    {
        int sum = people[i] + people[j];
        if (people[i] >= limit)
        {
            count++;
            i++;
        }
        else if (people[j] >= limit)
        {
            count++;
            j--;
        }
        else if (sum == limit)
        {
            count++;
            i++;
            j--;
        }
        else if (sum > limit)
        {
            j--;
            count++;
        }
        else if (sum < limit)
        {
            count++;
            i++;
            j--;
        }
    }
    if (i == j)
    {
        count++;
    }
    return count;
}
};