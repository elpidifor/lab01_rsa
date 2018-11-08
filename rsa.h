#pragma once

#include <map>
#include <string>
#include <vector>

namespace RSA
{
    using ui64 = unsigned long long int;

    // Генерирует открытый и закрытый ключи
    // открытый ключ - {e, n}
    // закрытый ключ - {d, n}
    // возвращает пару {public key, private key}
    std::pair<std::pair<ui64, ui64>, std::pair<ui64, ui64>> GenerateKeys();

    std::string BytesToHex(const std::vector<byte>&);
    std::vector<byte> BytesFromHex(const std::string&);

    class RSAEncryptor
    {
    public:
        RSAEncryptor(std::pair<ui64, ui64> publicKey);
        std::vector<byte> Encrypt(const std::vector<ui64>& message) const;
        std::vector<byte> Encrypt(const std::string& message) const;
    };
    
    class RSADecryptor
    {
    public:
        RSAEncryptor(std::pair<ui64, ui64> privateKey);
        std::vector<ui64> DecryptBytes(const std::vector<byte>& cipherText) const;
        std::string Decrypt(const std::vector<byte>& cipherText) const;
    };
};
