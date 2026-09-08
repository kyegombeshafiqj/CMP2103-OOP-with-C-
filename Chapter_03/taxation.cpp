// The income tax rate for individuals in business depends on the income bracket in which the individual falls.
// Resident individuals enjoy a tax free annual income threshold of UGX. 2,820,000 per annum. The
// balance is taxed at 10%, 20% or 30% depending on the income bracket. Individuals who earn
// above UGX 120,000,000 pa pay an additional 10% on the income above 120m.
// +----------------------+------------------------------------------+------------------------------------------+
// | CHARGEABLE INCOME, CY| RESIDENTS                                | NON-RESIDENTS                             |
// | (UGX Annual)         | RATE OF TAX                              | RATE OF TAX                               |
// +----------------------+------------------------------------------+------------------------------------------+
// | 0 to 2,820,000       | Nil                                      | CY x 10%                                  |
// | 2,820,000 to         | (CY - 2,820,000) x 10%                   | CY x 10%                                  |
// | 4,020,000            |                                          |                                           |
// | 4,020,000 to         | (CY - 4,020,000) x 20% + 120,000         | (CY - 4,020,000) x 20% + 402,000          |
// | 4,920,000            |                                          |                                           |
// | 4,920,000 to         | (CY - 4,920,000) x 30% + 300,000         | (CY - 4,920,000) x 30% + 582,000          |
// | 120,000,000          |                                          |                                           |
// | Above 120,000,000    | [(CY - 4,920,000) x 30% + 300,000]       | [(CY - 4,920,000) x 30% + 582,000]        |
// |                      | + [(CY - 120,000,000) x 10%]             | + [(CY - 120,000,000) x 10%]              |
// +----------------------+------------------------------------------+------------------------------------------+

// You are to write a program to compute personal income tax. Your program should prompt
// the user to enter the residence status and taxable income and then compute the tax. Enter 0 for
// resident and 1 for non-resident.

// Output
// (0-Resident, 1-Non-resident)
// Enter the residence status: 0
// Enter the taxable income: 4,000,000
// Tax is 118000.

#include <iomanip>
#include <iostream>

int main() {
	int residenceStatus;
	long double taxableIncome;

	std::cout << "(0-Resident, 1-Non-resident)\n";
	std::cout << "Enter the residence status: ";
	std::cin >> residenceStatus;
	std::cout << "Enter the taxable income: ";
	std::cin >> taxableIncome;

	if (!std::cin || (residenceStatus != 0 && residenceStatus != 1) || taxableIncome < 0) {
		std::cout << "Invalid input.\n";
		return 1;
	}

	long double tax;

	if (residenceStatus == 0) {
		if (taxableIncome <= 2820000) {
			tax = 0;
		} else if (taxableIncome <= 4020000) {
			tax = (taxableIncome - 2820000) * 0.10L;
		} else if (taxableIncome <= 4920000) {
			tax = (taxableIncome - 4020000) * 0.20L + 120000;
		} else {
			tax = (taxableIncome - 4920000) * 0.30L + 300000;
			if (taxableIncome > 120000000) {
				tax += (taxableIncome - 120000000) * 0.10L;
			}
		}
	} else {
		if (taxableIncome <= 4020000) {
			tax = taxableIncome * 0.10L;
		} else if (taxableIncome <= 4920000) {
			tax = (taxableIncome - 4020000) * 0.20L + 402000;
		} else {
			tax = (taxableIncome - 4920000) * 0.30L + 582000;
			if (taxableIncome > 120000000) {
				tax += (taxableIncome - 120000000) * 0.10L;
			}
		}
	}

	std::cout << "Tax is " << std::fixed << std::setprecision(0) << tax << ".\n";
	return 0;
}
