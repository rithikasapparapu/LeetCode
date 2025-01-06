class Solution {
public:
    vector<int> minOperations(string boxes) {
        int after = 0, before = 0;
        vector<int> answer;
        int prefixSum = 0;
        for(int i=0; i<boxes.size(); i++){
            if(boxes[i]=='1'){
                prefixSum += i;
                after++;
            }
        }
        for(int i=0; i<boxes.size(); i++){
            if(boxes[i]=='1'){
                after--;
                prefixSum -= i;
            }
            answer.push_back(prefixSum - i*after + i*before);
            if(boxes[i]=='1'){
                before++;
                prefixSum -= i;
            }
        }
        return answer;
    }
};