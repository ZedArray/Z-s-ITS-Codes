package oopq1;

public class Q16Fraction {
	
	public int numerator, denominator;
	
	//constructor for the fractions
	public Q16Fraction(int a, int b) {
		numerator = a;
		denominator = b;
	}
	
	//method to print out the fraction
	public String toString() {
		return numerator + "/" + denominator;
	}
	
	//method to multiply two fractions
	public Q16Fraction getProduct(Q16Fraction otherF) {
		Q16Fraction result = new Q16Fraction(numerator*otherF.numerator, denominator*otherF.denominator);
		return result;
	}
	
	//method to sum two fractions
	public Q16Fraction getSum(Q16Fraction otherF) {
		Q16Fraction result = new Q16Fraction((numerator*otherF.denominator) + (otherF.numerator*denominator), denominator*otherF.denominator);
		return result;
	}
}
