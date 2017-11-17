class NumMatrix {
    int** sumMat;
public:
    NumMatrix(vector<vector<int>> matrix) {
        sumMat = new int*[matrix.size()];
        for (int i = 0; i < matrix.size(); i++)
            sumMat[i] = new int[matrix[0].size() + 1];
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                sumMat[i][j+1] = matrix[i][j] + sumMat[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++)
            sum += sumMat[i][col2+1] - sumMat[i][col1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */