//Katie Taylor
//UIN:01122882
//Assignment01

#include "gradecalculator.h"

#include <algorithm>
#include <iterator>

void GradeCalculator::Load(std::istream& is)
{
	// TODO Load the grades without writing a loop
	
	std::istream_iterator<Grade> eos; //end-of-input stream iterator             
        std::istream_iterator<Grade> iit (is); //input stream iterator
	
	if(m_Grades.empty()) { //ensure <m_Grades> is empty
		copy(iit, eos, back_inserter(m_Grades)); //if true, copy values from input stream to <m_Grades>
	}
	else {
		std::cerr << "There is data currently being stored in <m_Grades>. Would you like to empty <m_Grades>?"
			  << "Press (1) to empty, (0) to terminate."; //ask user if they want to clear <m_Grades> & continue with program
		
		bool choice;
		std::cin >> choice; 
		
		if(choice) { 
			m_Grades.clear(); //if true (user selects 1), clear data currently stored in <m_Grades>
			copy(iit, eos, back_inserter(m_Grades)); //now proceed with copyibng values from input stream to <m_Grades>
		}
		else {
			abort(); //abort function if user wants to keep data in <m_Grades>
		}
	}
	
}
	
CountAverage GradeCalculator::CalculateAverage(Grade::Type type) const
{
	// TODO Calculate the count and average for the provided type without writing a loop

	CountAverage pair; //declare variable to store <count, average> for the requested Grade::Type

	for_each(m_Grades.begin(), m_Grades.end(), 
		[&] (const Grade &g)
	     	 {
		    if(g.GetType() == type) { //for_each grade in m_Grades, check if it's type is equivalent to the requested type
			pair.second += g.GetScore(); //if true, GetScore() of that grade & add its value to our running 'sum' of scores
			pair.first++; //increment the count for that grade type
		    }
	         });

	pair.second = pair.second / pair.first;	//divide the total sum of scores for that grade type by its count
	return pair; //return <count, average>
}
