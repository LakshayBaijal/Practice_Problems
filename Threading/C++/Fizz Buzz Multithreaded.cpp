class FizzBuzz {
private:
    int n;
    sem_t s1,s2,s3,s4;
public:
    FizzBuzz(int n) {
        this->n = n;
        sem_init(&s1,0,0);
        sem_init(&s2,0,0);
        sem_init(&s3,0,0);
        sem_init(&s4,0,1);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) 
    {
        while(true)
        {

        
        sem_wait(&s1);
        if(n==-1)
        {
            
            break;
        }
        printFizz();
        sem_post(&s4);
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) 
    {
        while(true)
        {
        sem_wait(&s2);
        if(n==-1)
        {
            break;
        }
        printBuzz();
        sem_post(&s4);
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) 
    {
        while(true)
        {
        sem_wait(&s3);
        if(n==-1)
        {
            break;
        }
        printFizzBuzz();
        sem_post(&s4);
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) 
    {

        for(int i = 1; i<n;i++)
        {
            sem_wait(&s4);
            if(i % 3 == 0 && i % 5 == 0)
            {
                sem_post(&s3);
                
            }
            else if(i % 3 == 0)
            {
                sem_post(&s1);
                
                
            }
            else if(i % 5 == 0)
            {
                sem_post(&s2);
                
            }
            else
            {
                printNumber(i);
                sem_post(&s4);
            }
        }

        n = -1;
        sem_post(&s1);
        sem_post(&s2);
        sem_post(&s3);

    }
};
