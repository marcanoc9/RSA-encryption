#include<iostream>
#include<math.h>
using namespace std;
// Finding gcd
int gcd(int x, int y) {
    int z;
    while (1) {
        z = x % y;
        if (z == 0)
            return y;
        x = y;
        y = z;
    }
}
int main() {
    //Choose any 2 random prime numbers
    double prime1 = 13;
    double  prime2 = 11;
    double n = prime1 * prime2; //Calculating n
    double trackcount;
    double phi = (prime1 - 1) * (prime2 - 1); //Calculating phi

    //Finding public key 'e'. Here 'e' stands for encrypt.
    double e = 7;

    //Checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; that means e and phi(n) are coprime.
    while (e < phi)
    {
        trackcount = gcd(e, phi);
        if (trackcount == 1)
            break;
        else
            e++;
    }
    //Finding private key 'd'. Here 'd' stands for decrypt.

    //Choosing the value of d such that it satisfies: d*e = 1 mod phi
    double d1 = 1 / e;
    double d = fmod(d1, phi);

    // Numerical Message which will be encrypted
    double msg = 9;

    //Encrypting the message
    double encrypted = pow(msg, e); //encrypt the message
    double decrypted = pow(encrypted, d);
    encrypted = fmod(encrypted, n);
    decrypted = fmod(decrypted, n);
    cout << "Original Message = " << msg;
    cout << "\n" << "prime1 = " << prime1;
    cout << "\n" << "prime2 = " << prime2;
    cout << "\n" << "n = (prime1)x(prime2) = " << prime1 << " x " << prime2 << " = " << n;
    cout << "\n" << "phi = " << phi;
    cout << "\n" << "e = " << e;
    cout << "\n" << "d = " << d;
    cout << "\n" << "Encrypted message = " << encrypted;
    cout << "\n" << "Decrypted message = " << decrypted;
    return 0;
}
