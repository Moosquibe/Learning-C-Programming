#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: displayloc <locale>");
        exit(EXIT_FAILURE);
    }
    setlocale(LC_ALL, argv[1]);
    struct lconv *locale_data = localeconv();

    printf("Decimal point: \"%s\"\n", locale_data->decimal_point);
    printf("Thousands separator: \"%s\"\n", locale_data->thousands_sep);
    printf("Grouping: \"%s\"\n", locale_data->grouping);
    printf("Monetary decimal point: \"%s\"\n", locale_data->mon_decimal_point);
    printf("Monetary thousands separator: \"%s\"\n", locale_data->mon_thousands_sep);
    printf("Monetary grouping: \"%s\"\n", locale_data->mon_grouping);
    printf("Positive sign: \"%s\"\n", locale_data->positive_sign);
    printf("Negative sign: \"%s\"\n", locale_data->negative_sign);
    printf("Currency symbol: \"%s\"\n", locale_data->currency_symbol);
    printf("International currency symbol: \"%s\"\n", locale_data->int_curr_symbol);
    printf("Number of digits after decimal point: \"%d\"\n", locale_data->frac_digits);
    printf("p_cs_precedes: \"%d\"\n", locale_data->p_cs_precedes);
    printf("n_cs_precedes: \"%d\"\n", locale_data->n_cs_precedes);
    printf("p_sep_by_space: \"%d\"\n", locale_data->p_sep_by_space);
    printf("n_sep_by_space: \"%d\"\n", locale_data->n_sep_by_space);
    printf("p_sign_posn: \"%d\"\n", locale_data->p_sign_posn);
    printf("n_sign_posn: \"%d\"\n", locale_data->n_sign_posn);
    printf("int_frac_digits: \"%d\"\n", locale_data->int_frac_digits);
    printf("int_p_cs_precedes: \"%d\"\n", locale_data->int_p_cs_precedes);
    printf("int_n_cs_precedes: \"%d\"\n", locale_data->int_n_cs_precedes);
    printf("int_p_sep_by_space: \"%d\"\n", locale_data->int_p_sep_by_space);
    printf("int_n_sep_by_space:\"%d\"\n", locale_data->int_n_sep_by_space);
    printf("int_p_sign_posn: \"%d\"\n", locale_data->int_p_sign_posn);
    printf("int_n_sign_posn: \"%d\"\n", locale_data->int_n_sign_posn);

    exit(EXIT_SUCCESS);
}