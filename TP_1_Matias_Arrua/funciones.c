#include <stdio.h>
#include <stdlib.h>

/** \brief funcion que recibe dos variables, las suma y devuelve el resultado.
 *
 * \param a float primer operando
 * \param b float segundo operando
 * \return float devuelve la suma de las dos variables
 *
 */
float suma(float a, float b) {
    float suma;
    suma = a + b;
    return suma;
}

/** \brief funcion que recibe dos variables, las resta y devuelve el resultado.
 *
 * \param a float primer operando
 * \param b float segundo operando
 * \return float devuelve la resta de las dos variables
 *
 */
float resta(float a, float b) {
    float resta;
    resta = a - b;
    return resta;
}

/** \brief funcion que recibe dos variables, las multiplica y devuelve el resultado.
 *
 * \param a float primer operando
 * \param b float segundo operando
 * \return float devuelve la multiplicacion de las dos variables
 *
 */
float multiplicar(float a, float b) {
    float multiplicacion;
    multiplicacion = a * b;
    return multiplicacion;
}

/** \brief funcion que recibe dos variables, realiza la division y devuelve el resultado. Tiene en cuenta posibles errores.
 *
 * \param a float primer operando
 * \param b float segundo operando
 * \return float devuelve la division de las dos variables
 *
 */
float dividir(float a, float b) {
    float division;
    division = a / b;
    return division;
}

/** \brief funcion que recibe una variable, realiza el factorial y devuelve el resultado.
 *
 * \param a float primer operando
 * \return float devuelve el factorial de la variable.
*/
float factorial(float a) {
    float resultado;

        if(a==1){
        return(1);
    }
    resultado=a*factorial(a-1);
    return(resultado);
}

