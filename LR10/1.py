import hashlib
from Crypto.PublicKey import RSA
from Crypto.Signature import pkcs1_15

m = "Шатуха Алексей Кириллович"
h = hashlib.md5(m.encode()).digest()
k = RSA.generate(2048)
s = pkcs1_15.new(k).sign(hashlib.md5(m.encode()))
print(f"MD5: {hashlib.md5(m.encode()).hexdigest()}\nSig: {s.hex()[:32]}...")
print("Valid:", pkcs1_15.new(k.publickey()).verify(hashlib.md5(m.encode()), s) or False)
print("Mod valid:", pkcs1_15.new(k.publickey()).verify(hashlib.md5((m+" ").encode()), s) or False)
