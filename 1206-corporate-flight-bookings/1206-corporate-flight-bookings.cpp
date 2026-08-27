class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        vector<int> seat(n, 0);

        for(int i = 0; i < bookings.size(); i++)
        {
            int first = bookings[i][0];
            int last = bookings[i][1];
            int seats = bookings[i][2];

            seat[first - 1] += seats;

            if(last < n)
                seat[last] -= seats;
        }

        for(int i = 1; i < n; i++)
        {
            seat[i] += seat[i - 1];
        }

        return seat;
    }
};