/* Brute force...correct solution, but will fail for larger array inputs (TLE) */
int hIndex(vector<int>& citations) {
        int n = citations.size();

        while(n){
            int count = 0;
            cout<< "n :"<< n <<endl;
            for (int i = 0; i<citations.size(); i++){
                if(citations[i]>= n) count++;
                cout<< "count :" << count << endl;
            }
            if( count >= n )
            return n;

            n--;
        }
          return 0;
}




/* optimized */
int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        int maxi = 0;
        for (int i =0 ; i< n; i++){
            if(citations[i]>= n-i) maxi = max(maxi, n-i);
            cout << maxi << endl;
        }
        return maxi;
    }