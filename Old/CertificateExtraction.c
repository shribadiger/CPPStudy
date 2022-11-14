#include <stdio.h>
#include <stdlib.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/pkcs12.h>

int main(int argc, char **argv)
{
    FILE *fp;
    EVP_PKEY *pkey = NULL;
    X509 *cert = NULL;
    STACK_OF(X509) *ca = NULL;
    PKCS12 *p12 = NULL;
    int i, ret = EXIT_FAILURE;

    if (argc != 4) {
        fprintf(stderr, "Usage: pkread p12file password opfile\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    p12 = d2i_PKCS12_fp(fp, NULL);
    fclose(fp);
    if (p12 == NULL) {
        fprintf(stderr, "Error reading PKCS#12 file\n");
        ERR_print_errors_fp(stderr);
        goto err;
    }
    if (!PKCS12_parse(p12, argv[2], &pkey, &cert, &ca)) {
        fprintf(stderr, "Error parsing PKCS#12 file\n");
        ERR_print_errors_fp(stderr);
        goto err;
    }
    PKCS12_free(p12);
    if ((fp = fopen(argv[3], "w")) == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        goto err;
    }
    if (pkey != NULL) {
        fprintf(fp, "***Private Key***\n");
        PEM_write_PrivateKey(fp, pkey, NULL, NULL, 0, NULL, NULL);
        printf("Private Key : %s",pkey);
    }
    if (cert != NULL) {
        fprintf(fp, "***User Certificate***\n");
        PEM_write_X509_AUX(fp, cert);
    }
    if (ca != NULL && sk_X509_num(ca) > 0) {
        fprintf(fp, "***Other Certificates***\n");
        for (i = 0; i < sk_X509_num(ca); i++)
            PEM_write_X509_AUX(fp, sk_X509_value(ca, i));
    }
    fclose(fp);

    ret = EXIT_SUCCESS;

 err:
    X509_free(cert);
    EVP_PKEY_free(pkey);
    sk_X509_pop_free(ca, X509_free);

    return ret;
}
