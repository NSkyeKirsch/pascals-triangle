#include <iostream>
#include <vector>

using namespace std;

vector<int> buildRow(int currentRow, vector<vector<int>>& matrix){
    
    vector<int> last_row = matrix[currentRow-1];
    vector<int> new_row = {1};

    for(int i = 0; i < last_row.size()-1; i++){
        new_row.push_back((last_row[i] + last_row[i+1]));
    }
    new_row.push_back(1);
    
    return new_row;
}

vector<vector<int>> generate(int numRows){
    
    vector<vector<int>> matrix = {{1}};

    for(int i = 1; i < numRows; i++){
        matrix.push_back(buildRow(i, matrix));
    }

    return matrix;

}

void print_output(vector<vector<int>>& matrix){
    cout << "\nPrinting output:";
    cout << "[";
    for(vector<int> row : matrix){
        cout << "[";
        for(int element : row){
            cout << element << " ";
        }
        cout << "]";
    }
    cout << "]\n";
}

int main(){
    
    int input_rows;
    cout << "Enter Number of Rows: ";
    cin >> input_rows;
    
    vector<vector<int>> output_matrix = generate(input_rows);
    
    //vector<vector<int>> test_output = {{1}, {1,2,1}, {1,3,3,1}};

    print_output(output_matrix);

    return 0;
}
