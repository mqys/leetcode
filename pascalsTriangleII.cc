class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // vector<int> result, temp;
        // result.push_back(1);
        // if (rowIndex < 1) return result;
        // for (int i = 0; i < rowIndex; ++i) {
        //     temp.resize(0);
        //     for (int j = 0; j < result.size(); ++j) {
        //         if (j == 0) 
        //             temp.push_back(1);
        //         else
        //             temp.push_back(result[j] + result[j-1]);
        //     }
        //     temp.push_back(1);
        //     result = move(temp);
        // }
        // return result;
        
        vector<int> result(rowIndex + 1, 0);
        for (int i = 0; i <= rowIndex; ++i) { // control the times
            for (int j = i; j >= 0; --j) { // control the num of char (must reverse order)
                if (j == i) result[j] = 1;
                else
                    result[j] += result[j-1];
            }
        }
        return result;        
    }
};