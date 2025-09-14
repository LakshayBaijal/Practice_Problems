class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        return max(function(answerKey,k,'F'),function(answerKey,k,'T'));
    }

    int function(string answerKey, int k,int wrong)
    {
        int right = 0;
        int left = 0;
        int count = 0;
        int maximum = 0;

        for(right = 0; right < answerKey.size();right ++)
        {
            if(answerKey[right] == wrong)
            {
                count ++;
            }

            while(count > k)
            {
                if(answerKey[left] == wrong)
                {
                    count --;
                }
                left ++;
            }
            maximum = max(maximum,right - left + 1);

        }   

        return maximum;
    }
};
