

int main(){

    const int ARRAY = 5;
    //....
    int array[ARRAY];

	// A loop which will fill an array with random values
	// Initalize randomTargets objects with passed in arrays
    for(int i = 0; i < ARRAY; i++){
        array[i] = rand() % MAX;
    }
    unique_ptr<randomTargets> P1(new randomTargets(array));

    for(int i = 0; i < ARRAY; i++){
        array[i] = rand() % 10;
    }
    unique_ptr<randomTargets> P2(new randomTargets(array));

    for(int i = 0; i < ARRAY; i++){
        array[i] = rand() % 10;
    }
    unique_ptr<randomTargets> P3(new randomTargets(array));
	
	for(int i = 0; i < ARRAY; i++){
        array[i] = rand() % 10;
    }
    shared_ptr<randomTargets> P4(new randomTargets(array));
	
	shared_ptr<randomTargets> P5(new randomTargets(*P4));  // tests copy constructor
	
	//....

// Move copy constructor
    
    cout << "Testing move copy constructor with vector and Object 1" 
    << endl << endl;
    vector<shared_ptr<randomTargets>> v1; 
    v1.push_back(move(P1));
   cout << endl << "Here are the statistics of Object 1 within vector" 
         << endl
    << "Object # with most highGuess amount: "
    <<  v1[0]->returnObjHighestGuesses(highStatistic) << endl
    << "High guess amount: " << highStatistic << endl
    << "Object # with most lowGuess amount: "
    <<  v1[0]->returnObjLowestGuesses(lowStatistic) << endl
    << "Low guess amount: " << lowStatistic << endl 
    << "Total Guesses: " << v1[0]->returnTotalGuesses() << endl
    << "Numbers left unknown: " << v1[0]->returnTargetsLeft() << endl 
    << endl;


    // Move overloaded= operator

    // In vector
    cout << "Testing move overloaded= with Obj 1 "
         << "assigned to Obj 2 within vector" << endl
         << endl
         <<"Printing Object 2 statistics: " << endl << endl
         << "Object # with most highGuess amount: "
         <<  P2->returnObjHighestGuesses(highStatistic) << endl
         << "High guess amount: " << highStatistic << endl
         << "Object # with most lowGuess amount: "
         <<  P2->returnObjLowestGuesses(lowStatistic) << endl
         << "Low guess amount: " << lowStatistic << endl 
         << "Total Guesses: " << P2->returnTotalGuesses() << endl
         << "Numbers left unknown: " << P2->returnTargetsLeft() << endl;
		 
    v1[0] = move(P2);
	
    cout << endl 
         << "Here are the statistics of Obj 1 move overloaded= in vector" 
         << endl
         << "Object # with most highGuess amount: "
         <<  v1[0]->returnObjHighestGuesses(highStatistic) << endl
         << "High guess amount: " << highStatistic << endl
         << "Object # with most lowGuess amount: "
         <<  v1[0]->returnObjLowestGuesses(lowStatistic) << endl
         << "Low guess amount: " << lowStatistic << endl 
         << "Total Guesses: " << v1[0]->returnTotalGuesses() << endl
         << "Numbers left unknown: " << v1[0]->returnTargetsLeft() << endl 
         << endl;
         
    // Out of vector
     P5 = move(v1[0]);
    cout << endl 
         << "Here are the statistics of Obj 5 move overloaded= out of vector" 
         << endl
         << "Object # with most highGuess amount: "
         <<  P5->returnObjHighestGuesses(highStatistic) << endl
         << "High guess amount: " << highStatistic << endl
         << "Object # with most lowGuess amount: "
         <<  P5->returnObjLowestGuesses(lowStatistic) << endl
         << "Low guess amount: " << lowStatistic << endl 
         << "Total Guesses: " << P5->returnTotalGuesses() << endl
         << "Numbers left unknown: " << P5->returnTargetsLeft() << endl 
         << endl;
    cout << "Thank you for using this driver! End of Tests" << endl << endl;

    


    return 0;
}

