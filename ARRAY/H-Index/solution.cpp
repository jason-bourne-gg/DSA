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
