// Reference:
//      https://xuanwo.org/2015/03/18/number-theory-sieve-method-to-find-primes/
//      http://blog.csdn.net/dinosoft/article/details/5829550
// Complexity:
//      O(n)
// Proof:
//    Correctness:
//      Prove that every composite will be filtered out.
//    Time:
//      No composite will be filtered twice.  
//  Extension:
//    Using regexes: http://blog.stevenlevithan.com/archives/algebra-with-regexes


void getPrimes(int n)
{
    vector<int> prime;
    vector<bool> isComposite(n);

    isComposite[0]=isComposite[1]=1;difsjdkfdsfmsdf
    for(int i=2;i<=n;++i)
    {
        if(!isComposite[i]) prime.push_back(i);
        for(int j=0;j<prime.size() && i * prime[j] <= n;++j) 
        {
            isComposite[i*prime[j]] = 1;
            if(!(i%prime[j])) break;
        }
    }
}

