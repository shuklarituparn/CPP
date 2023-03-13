cmake_minimum_required(VERSION 3.24)
project(CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories("10-Operator Overloading/01.Mystring-copy-assignment")
include_directories("10-Operator Overloading/02.Mystring-move-assignment")
include_directories("10-Operator Overloading/03.Mystring-operators")
include_directories("10-Operator Overloading/04.Mystring-operator-functions")
include_directories("10-Operator Overloading/05.Mystring-insertion-extraction")
include_directories("10-Operator Overloading/Challenge")
include_directories("10-Operator Overloading/Challenge-Solution1")
include_directories("10-Operator Overloading/Challenge-Solution2")
include_directories("10-Operator Overloading/00.Mystring-start")
include_directories(11-Inheritance/01.DerivingOurFirstClass)
include_directories(11-Inheritance/06.RedefiningBaseClassMethods)
include_directories(11-Inheritance/Challenge)
include_directories(11-Inheritance/ChallengeSolution)
include_directories(12-Polymorphism/Challenge)
include_directories(12-Polymorphism/ChallengeSolution)
include_directories(12-Polymorphism/ChallengeSolution-Part1)
include_directories(12-Polymorphism/ChallengeSolution-Part2)
include_directories("13-Smart Pointers/01.UniquePointers")
include_directories("13-Smart Pointers/02.SharedPointers")
include_directories("14-Exception handling/Challenge")
include_directories("14-Exception handling/ChallengeSolution")
include_directories("14-Exception handling/ConstructorException")
include_directories("9-Classes and Objects (OOP)/04.ImplementingMethods2")
include_directories("9-Classes and Objects (OOP)/16.0 StaticClassMembers")
include_directories("9-Classes and Objects (OOP)/17.Friends")
include_directories("9-Classes and Objects (OOP)/Challenge")
include_directories("9-Classes and Objects (OOP)/ChallengeSolution")

add_executable(CPP
        1-Basics/hello_world.cpp
        1-Basics/input_output.cpp
        1-Basics/linker_error.cpp
        1-Basics/logic.cpp
        1-Basics/Section1_Challenge.cpp
        "10-Operator Overloading/01.Mystring-copy-assignment/main.cpp"
        "10-Operator Overloading/01.Mystring-copy-assignment/Mystring.cpp"
        "10-Operator Overloading/01.Mystring-copy-assignment/Mystring.h"
        "10-Operator Overloading/02.Mystring-move-assignment/main.cpp"
        "10-Operator Overloading/02.Mystring-move-assignment/Mystring.cpp"
        "10-Operator Overloading/02.Mystring-move-assignment/Mystring.h"
        "10-Operator Overloading/03.Mystring-operators/main.cpp"
        "10-Operator Overloading/03.Mystring-operators/Mystring.cpp"
        "10-Operator Overloading/03.Mystring-operators/Mystring.h"
        "10-Operator Overloading/04.Mystring-operator-functions/main.cpp"
        "10-Operator Overloading/04.Mystring-operator-functions/Mystring.cpp"
        "10-Operator Overloading/04.Mystring-operator-functions/Mystring.h"
        "10-Operator Overloading/05.Mystring-insertion-extraction/main.cpp"
        "10-Operator Overloading/05.Mystring-insertion-extraction/Mystring.cpp"
        "10-Operator Overloading/05.Mystring-insertion-extraction/Mystring.h"
        "10-Operator Overloading/Challenge/main.cpp"
        "10-Operator Overloading/Challenge/Mystring.cpp"
        "10-Operator Overloading/Challenge/Mystring.h"
        "10-Operator Overloading/Challenge-Solution1/main.cpp"
        "10-Operator Overloading/Challenge-Solution1/Mystring.cpp"
        "10-Operator Overloading/Challenge-Solution1/Mystring.h"
        "10-Operator Overloading/Challenge-Solution2/main.cpp"
        "10-Operator Overloading/Challenge-Solution2/Mystring.cpp"
        "10-Operator Overloading/Challenge-Solution2/Mystring.h"
        "10-Operator Overloading/00.Mystring-start/main.cpp"
        "10-Operator Overloading/00.Mystring-start/Mystring.cpp"
        "10-Operator Overloading/00.Mystring-start/Mystring.h"
        11-Inheritance/01.DerivingOurFirstClass/Account.cpp
        11-Inheritance/01.DerivingOurFirstClass/Account.h
        11-Inheritance/01.DerivingOurFirstClass/main.cpp
        11-Inheritance/01.DerivingOurFirstClass/Savings_Account.cpp
        11-Inheritance/01.DerivingOurFirstClass/Savings_Account.h
        11-Inheritance/02.ProtectedMembersClassAccess/main.cpp
        11-Inheritance/03.ConstructorsAndDestructors/main.cpp
        11-Inheritance/04.BaseClassInitialization/main.cpp
        11-Inheritance/05.CopyConstructorAssignmentOperator/main.cpp
        11-Inheritance/06.RedefiningBaseClassMethods/Account.cpp
        11-Inheritance/06.RedefiningBaseClassMethods/Account.h
        11-Inheritance/06.RedefiningBaseClassMethods/main.cpp
        11-Inheritance/06.RedefiningBaseClassMethods/Savings_Account.cpp
        11-Inheritance/06.RedefiningBaseClassMethods/Savings_Account.h
        11-Inheritance/Challenge/Account.cpp
        11-Inheritance/Challenge/Account.h
        11-Inheritance/Challenge/Account_Util.cpp
        11-Inheritance/Challenge/Account_Util.h
        11-Inheritance/Challenge/main.cpp
        11-Inheritance/Challenge/Savings_Account.cpp
        11-Inheritance/Challenge/Savings_Account.h
        11-Inheritance/ChallengeSolution/Account.cpp
        11-Inheritance/ChallengeSolution/Account.h
        11-Inheritance/ChallengeSolution/Account_Util.cpp
        11-Inheritance/ChallengeSolution/Account_Util.h
        11-Inheritance/ChallengeSolution/Checking_Account.cpp
        11-Inheritance/ChallengeSolution/Checking_Account.h
        11-Inheritance/ChallengeSolution/main.cpp
        11-Inheritance/ChallengeSolution/Savings_Account.cpp
        11-Inheritance/ChallengeSolution/Savings_Account.h
        11-Inheritance/ChallengeSolution/Trust_Account.cpp
        11-Inheritance/ChallengeSolution/Trust_Account.h
        12-Polymorphism/01.BaseClassPointers/main.cpp
        12-Polymorphism/02.VirtualFunctions/main.cpp
        12-Polymorphism/03.VirtualDestructors/main.cpp
        12-Polymorphism/04.UsingOverride/main.cpp
        12-Polymorphism/05.UsingFinal/main.cpp
        12-Polymorphism/06.BaseClassReferences/main.cpp
        12-Polymorphism/07.PureVirtualFunctions/main.cpp
        12-Polymorphism/08.Interfaces/main.cpp
        12-Polymorphism/09.Interfaces-Complete/main.cpp
        12-Polymorphism/Challenge/Account.cpp
        12-Polymorphism/Challenge/Account.h
        12-Polymorphism/Challenge/Account_Util.cpp
        12-Polymorphism/Challenge/Account_Util.h
        12-Polymorphism/Challenge/Checking_Account.cpp
        12-Polymorphism/Challenge/Checking_Account.h
        12-Polymorphism/Challenge/main.cpp
        12-Polymorphism/Challenge/Savings_Account.cpp
        12-Polymorphism/Challenge/Savings_Account.h
        12-Polymorphism/Challenge/Trust_Account.cpp
        12-Polymorphism/Challenge/Trust_Account.h
        12-Polymorphism/ChallengeSolution/Account.cpp
        12-Polymorphism/ChallengeSolution/Account.h
        12-Polymorphism/ChallengeSolution/Account_Util.cpp
        12-Polymorphism/ChallengeSolution/Account_Util.h
        12-Polymorphism/ChallengeSolution/Checking_Account.cpp
        12-Polymorphism/ChallengeSolution/Checking_Account.h
        12-Polymorphism/ChallengeSolution/I_Printable.cpp
        12-Polymorphism/ChallengeSolution/I_Printable.h
        12-Polymorphism/ChallengeSolution/main.cpp
        12-Polymorphism/ChallengeSolution/Savings_Account.cpp
        12-Polymorphism/ChallengeSolution/Savings_Account.h
        12-Polymorphism/ChallengeSolution/Trust_Account.cpp
        12-Polymorphism/ChallengeSolution/Trust_Account.h
        12-Polymorphism/ChallengeSolution-Part1/Account.cpp
        12-Polymorphism/ChallengeSolution-Part1/Account.h
        12-Polymorphism/ChallengeSolution-Part1/Account_Util.cpp
        12-Polymorphism/ChallengeSolution-Part1/Account_Util.h
        12-Polymorphism/ChallengeSolution-Part1/Checking_Account.cpp
        12-Polymorphism/ChallengeSolution-Part1/Checking_Account.h
        12-Polymorphism/ChallengeSolution-Part1/main.cpp
        12-Polymorphism/ChallengeSolution-Part1/Savings_Account.cpp
        12-Polymorphism/ChallengeSolution-Part1/Savings_Account.h
        12-Polymorphism/ChallengeSolution-Part1/Trust_Account.cpp
        12-Polymorphism/ChallengeSolution-Part1/Trust_Account.h
        12-Polymorphism/ChallengeSolution-Part2/Account.cpp
        12-Polymorphism/ChallengeSolution-Part2/Account.h
        12-Polymorphism/ChallengeSolution-Part2/Account_Util.cpp
        12-Polymorphism/ChallengeSolution-Part2/Account_Util.h
        12-Polymorphism/ChallengeSolution-Part2/Checking_Account.cpp
        12-Polymorphism/ChallengeSolution-Part2/Checking_Account.h
        12-Polymorphism/ChallengeSolution-Part2/I_Printable.cpp
        12-Polymorphism/ChallengeSolution-Part2/I_Printable.h
        12-Polymorphism/ChallengeSolution-Part2/main.cpp
        12-Polymorphism/ChallengeSolution-Part2/Savings_Account.cpp
        12-Polymorphism/ChallengeSolution-Part2/Savings_Account.h
        12-Polymorphism/ChallengeSolution-Part2/Trust_Account.cpp
        12-Polymorphism/ChallengeSolution-Part2/Trust_Account.h
        12-Polymorphism/TheProblem/main.cpp
        "13-Smart Pointers/01.UniquePointers/Account.cpp"
        "13-Smart Pointers/01.UniquePointers/Account.h"
        "13-Smart Pointers/01.UniquePointers/Account_Util.cpp"
        "13-Smart Pointers/01.UniquePointers/Account_Util.h"
        "13-Smart Pointers/01.UniquePointers/Checking_Account.cpp"
        "13-Smart Pointers/01.UniquePointers/Checking_Account.h"
        "13-Smart Pointers/01.UniquePointers/I_Printable.cpp"
        "13-Smart Pointers/01.UniquePointers/I_Printable.h"
        "13-Smart Pointers/01.UniquePointers/main.cpp"
        "13-Smart Pointers/01.UniquePointers/Savings_Account.cpp"
        "13-Smart Pointers/01.UniquePointers/Savings_Account.h"
        "13-Smart Pointers/01.UniquePointers/Trust_Account.cpp"
        "13-Smart Pointers/01.UniquePointers/Trust_Account.h"
        "13-Smart Pointers/02.SharedPointers/Account.cpp"
        "13-Smart Pointers/02.SharedPointers/Account.h"
        "13-Smart Pointers/02.SharedPointers/Account_Util.cpp"
        "13-Smart Pointers/02.SharedPointers/Account_Util.h"
        "13-Smart Pointers/02.SharedPointers/Checking_Account.cpp"
        "13-Smart Pointers/02.SharedPointers/Checking_Account.h"
        "13-Smart Pointers/02.SharedPointers/I_Printable.cpp"
        "13-Smart Pointers/02.SharedPointers/I_Printable.h"
        "13-Smart Pointers/02.SharedPointers/main.cpp"
        "13-Smart Pointers/02.SharedPointers/Savings_Account.cpp"
        "13-Smart Pointers/02.SharedPointers/Savings_Account.h"
        "13-Smart Pointers/02.SharedPointers/Trust_Account.cpp"
        "13-Smart Pointers/02.SharedPointers/Trust_Account.h"
        "13-Smart Pointers/03.WeakPointers/main.cpp"
        "13-Smart Pointers/04.CustomDeleters/main.cpp"
        "13-Smart Pointers/Challenge/main.cpp"
        "13-Smart Pointers/ChallengeSolution/main.cpp"
        "14-Exception handling/01.DivideByZero/main.cpp"
        "14-Exception handling/02.1.DivideByZeroExceptionClasses/main.cpp"
        "14-Exception handling/02.DivideByZeroException/main.cpp"
        "14-Exception handling/03.CatchCPPExceptions/main.cpp"
        "14-Exception handling/04.StackUnwinding/main.cpp"
        "14-Exception handling/Challenge/Account.cpp"
        "14-Exception handling/Challenge/Account.h"
        "14-Exception handling/Challenge/Account_Util.cpp"
        "14-Exception handling/Challenge/Account_Util.h"
        "14-Exception handling/Challenge/Checking_Account.cpp"
        "14-Exception handling/Challenge/Checking_Account.h"
        "14-Exception handling/Challenge/I_Printable.cpp"
        "14-Exception handling/Challenge/I_Printable.h"
        "14-Exception handling/Challenge/IllegalBalanceException.h"
        "14-Exception handling/Challenge/main.cpp"
        "14-Exception handling/Challenge/Savings_Account.cpp"
        "14-Exception handling/Challenge/Savings_Account.h"
        "14-Exception handling/Challenge/Trust_Account.cpp"
        "14-Exception handling/Challenge/Trust_Account.h"
        "14-Exception handling/ChallengeSolution/Account.cpp"
        "14-Exception handling/ChallengeSolution/Account.h"
        "14-Exception handling/ChallengeSolution/Account_Util.cpp"
        "14-Exception handling/ChallengeSolution/Account_Util.h"
        "14-Exception handling/ChallengeSolution/Checking_Account.cpp"
        "14-Exception handling/ChallengeSolution/Checking_Account.h"
        "14-Exception handling/ChallengeSolution/I_Printable.cpp"
        "14-Exception handling/ChallengeSolution/I_Printable.h"
        "14-Exception handling/ChallengeSolution/IllegalBalanceException.h"
        "14-Exception handling/ChallengeSolution/InsufficientFundsException.h"
        "14-Exception handling/ChallengeSolution/main.cpp"
        "14-Exception handling/ChallengeSolution/Savings_Account.cpp"
        "14-Exception handling/ChallengeSolution/Savings_Account.h"
        "14-Exception handling/ChallengeSolution/Trust_Account.cpp"
        "14-Exception handling/ChallengeSolution/Trust_Account.h"
        "14-Exception handling/ConstructorException/Account.cpp"
        "14-Exception handling/ConstructorException/Account.h"
        "14-Exception handling/ConstructorException/Account_Util.cpp"
        "14-Exception handling/ConstructorException/Account_Util.h"
        "14-Exception handling/ConstructorException/Checking_Account.cpp"
        "14-Exception handling/ConstructorException/Checking_Account.h"
        "14-Exception handling/ConstructorException/I_Printable.cpp"
        "14-Exception handling/ConstructorException/I_Printable.h"
        "14-Exception handling/ConstructorException/IllegalBalanceException.h"
        "14-Exception handling/ConstructorException/main.cpp"
        "14-Exception handling/ConstructorException/Savings_Account.cpp"
        "14-Exception handling/ConstructorException/Savings_Account.h"
        "14-Exception handling/ConstructorException/Trust_Account.cpp"
        "14-Exception handling/ConstructorException/Trust_Account.h"
        "14-Exception handling/MilesPerGallonFunction/main.cpp"
        "14-Exception handling/MilesPerGallonFunctionExceptionClasses/main.cpp"
        "14-Exception handling/MPGFunctionExceptionInheritance/main.cpp"
        "14-Exception handling/MPGFunctionMultipleExceptions/main.cpp"
        "14-Exception handling/MPGRethrow/main.cpp"
        "15-I.O. Streams   /O and Streams/Challenge_1/main.cpp"
        "15-I.O. Streams   /O and Streams/Challenge_1_Solution/main.cpp"
        "15-I.O. Streams   /O and Streams/Challenge_2/main.cpp"
        "15-I.O. Streams   /O and Streams/Challenge_2_Solution/main.cpp"
        "15-I.O. Streams   /O and Streams/Challenge_3/main.cpp"
        "15-I.O. Streams   /O and Streams/Challenge_3_Solution/main.cpp"
        "15-I.O. Streams   /O and Streams/Challenge_4/main.cpp"
        "15-I.O. Streams   /O and Streams/Challenge_4_Solution/main.cpp"
        "15-I.O. Streams   /O and Streams/Challenge_5/main.cpp"
        "15-I.O. Streams   /O and Streams/Challenge_5_Solution/main.cpp"
        "15-I.O. Streams   /O and Streams/CopyFile_2/main.cpp"
        "15-I.O. Streams   /O and Streams/Manip_Base/main.cpp"
        "15-I.O. Streams   /O and Streams/Manip_Boolean/main.cpp"
        "15-I.O. Streams   /O and Streams/Manip_Fields/main.cpp"
        "15-I.O. Streams   /O and Streams/Manip_Floating/main.cpp"
        "15-I.O. Streams   /O and Streams/ReadFile_1/main.cpp"
        "15-I.O. Streams   /O and Streams/ReadFile_2/main.cpp"
        "15-I.O. Streams   /O and Streams/ReadFile_3/main.cpp"
        "15-I.O. Streams   /O and Streams/ReadFile_4/main.cpp"
        "15-I.O. Streams   /O and Streams/StringStream/main.cpp"
        "15-I.O. Streams   /O and Streams/WriteFile_1/main.cpp"
        "15-I.O. Streams   /O and Streams/WriteFIle_2/main.cpp"
        "16- Standard Template Library- STL/01.Macros/main.cpp"
        "16- Standard Template Library- STL/02.FunctionTemplates/main.cpp"
        "16- Standard Template Library- STL/03.ClassTemplates/main.cpp"
        "16- Standard Template Library- STL/04.ClassTemplateArray/main.cpp"
        "16- Standard Template Library- STL/05.Iterators/main.cpp"
        "16- Standard Template Library- STL/06.Algorithms/main.cpp"
        "16- Standard Template Library- STL/07.Array/main.cpp"
        "16- Standard Template Library- STL/08.Vector/main.cpp"
        "16- Standard Template Library- STL/09.Deque/main.cpp"
        "16- Standard Template Library- STL/10.List/main.cpp"
        "16- Standard Template Library- STL/11.Set/main.cpp"
        "16- Standard Template Library- STL/12.Map/main.cpp"
        "16- Standard Template Library- STL/13.Stack/main.cpp"
        "16- Standard Template Library- STL/14.Queue/main.cpp"
        "16- Standard Template Library- STL/15.PriorityQueue/main.cpp"
        "16- Standard Template Library- STL/Challenge_1/main.cpp"
        "16- Standard Template Library- STL/Challenge_1_Solution/main.cpp"
        "16- Standard Template Library- STL/Challenge_2/main.cpp"
        "16- Standard Template Library- STL/Challenge_2_Solution/main.cpp"
        "16- Standard Template Library- STL/Challenge_3/main.cpp"
        "16- Standard Template Library- STL/Challenge_3_Solution/main.cpp"
        "16- Standard Template Library- STL/Challenge_4/main.cpp"
        "16- Standard Template Library- STL/Challenge_4_Solution/main.cpp"
        "17- Lambda Expressions/01.StatelessLambda/main.cpp"
        "17- Lambda Expressions/02.StatefulLambdas/main.cpp"
        "17- Lambda Expressions/03.STL_Lambdas/main.cpp"
        "17- Lambda Expressions/FunctionObjects/main.cpp"
        "18- Enumerations/01.Enumerations/ScopedEnums/main.cpp"
        "18- Enumerations/01.Enumerations/UnscopedEnums/main.cpp"
        "18- Enumerations/02.UnscopedEnums/main.cpp"
        "18- Enumerations/03.ScopedEnums/main.cpp"
        2-Constants/const.cpp
        2-Constants/sizeof.cpp
        2-Constants/variables.cpp
        "3-Arrays and Vectors/array.cpp"
        "3-Arrays and Vectors/section_challenge.cpp"
        "3-Arrays and Vectors/vector_acess.cpp"
        "3-Arrays and Vectors/vector_capacity.cpp"
        "3-Arrays and Vectors/vector_modifiers.cpp"
        "3-Arrays and Vectors/vectors.cpp"
        "3-Arrays and Vectors/vectors_iterators.cpp"
        "4-Statement and Operators/Euros/main.cpp"
        "4-Statement and Operators/01.AssignmentOperator.cpp"
        "4-Statement and Operators/02. ArithmeticOperators.cpp"
        "4-Statement and Operators/03. IncrementDecrementOperators.cpp"
        "4-Statement and Operators/04. MixedExpressions.cpp"
        "4-Statement and Operators/05. EqualityOperators.cpp"
        "4-Statement and Operators/06. RelationalOperators.cpp"
        "4-Statement and Operators/07.LogicalOperators.cpp"
        "4-Statement and Operators/assignments.cpp"
        "4-Statement and Operators/challenge.cpp"
        "5-Program Flow/01. if_statement.cpp"
        "5-Program Flow/02. ifElse.cpp"
        "5-Program Flow/03.conditionalOperator.cpp"
        "5-Program Flow/04.forLoop.cpp"
        "5-Program Flow/05.ranged_for_loop.cpp"
        "5-Program Flow/06.whileLoop.cpp"
        "5-Program Flow/07.DoWhile.cpp"
        "5-Program Flow/challenge.cpp"
        "5-Program Flow/challengeSolution.cpp"
        "5-Program Flow/driving.cpp"
        "5-Program Flow/driving_nested_if.cpp"
        "5-Program Flow/grades.cpp"
        "5-Program Flow/histogram.cpp"
        "5-Program Flow/multiplocation_table.cpp"
        "5-Program Flow/shipping.cpp"
        "5-Program Flow/switch.cpp"
        "5-Program Flow/switchEnum.cpp"
        "5-Program Flow/vector1.cpp"
        "5-Program Flow/while_challenge.cpp"
        "6-Characters and strings/00.CharFunctions/main.cpp"
        "6-Characters and strings/01. CStyleStrings/main.cpp"
        "6-Characters and strings/02. CPPStrings/main.cpp"
        "6-Characters and strings/Challenge/main.cpp"
        "6-Characters and strings/ChallengeSolution/main.cpp"
        "6-Characters and strings/cpp_string_2.cpp"
        "6-Characters and strings/string_challenge.cpp"
        7-Functions/01.FunctionDefinitions/main.cpp
        7-Functions/02.FunctionPrototypes/main.cpp
        7-Functions/03.FunctionParamters/main.cpp
        "7-Functions/04. DefaultArguments/main.cpp"
        "7-Functions/05. FunctionOverloading/main.cpp"
        "7-Functions/06. ArraysAndFunctions/challenge.cpp"
        "7-Functions/06. ArraysAndFunctions/main.cpp"
        7-Functions/07.PassByReference/main.cpp
        7-Functions/07.PassByReference/passbyreference_challenge.cpp
        "7-Functions/08. ScopeExample/main.cpp"
        "7-Functions/09. HowFunctionCallsWork/main.cpp"
        7-Functions/Challenge/main.cpp
        7-Functions/ChallengeSolution/main.cpp
        7-Functions/Factorial/main.cpp
        7-Functions/Fibonacci/challenge_penny.cpp
        7-Functions/Fibonacci/main.cpp
        7-Functions/Math/main.cpp
        7-Functions/Random/main.cpp
        "8-Pointers and references/01.SimplePointers/main.cpp"
        "8-Pointers and references/02.Dereference/main.cpp"
        "8-Pointers and references/03.DynamicMemory/main.cpp"
        "8-Pointers and references/04.AraysAndPointers/main.cpp"
        "8-Pointers and references/05.PointerArithmetic/main.cpp"
        "8-Pointers and references/06.PassingPointers/main.cpp"
        "8-Pointers and references/07.PassingPointers2/main.cpp"
        "8-Pointers and references/08.PassingPointers3/main.cpp"
        "8-Pointers and references/09.ReturnPointer/main.cpp"
        "8-Pointers and references/11.References/main.cpp"
        "8-Pointers and references/Challenge/main.cpp"
        "8-Pointers and references/Challenge/main1.cpp"
        "8-Pointers and references/ChallengeSolution/main.cpp"
        "8-Pointers and references/Debugger/main.cpp"
        "8-Pointers and references/pointer_comparision.cpp"
        "9-Classes and Objects (OOP)/01.DeclareClassAndObjects/main.cpp"
        "9-Classes and Objects (OOP)/02.AccessingClassMembers/main.cpp"
        "9-Classes and Objects (OOP)/03.ImplementingMethods/main.cpp"
        "9-Classes and Objects (OOP)/04.ImplementingMethods2/Account.cpp"
        "9-Classes and Objects (OOP)/04.ImplementingMethods2/Account.h"
        "9-Classes and Objects (OOP)/04.ImplementingMethods2/main.cpp"
        "9-Classes and Objects (OOP)/05.Adding_more_pblcmethod_to_class/challenge.cpp"
        "9-Classes and Objects (OOP)/06.ConstructorsAndDestructors/main.cpp"
        "9-Classes and Objects (OOP)/07.DefaultConstructor/main.cpp"
        "9-Classes and Objects (OOP)/08.DefaultConstructorParameters/main.cpp"
        "9-Classes and Objects (OOP)/09.ConstructorInitializationLists/main.cpp"
        "9-Classes and Objects (OOP)/10.DelegatingConstructors/main.cpp"
        "9-Classes and Objects (OOP)/11.CopyConstructor/main.cpp"
        "9-Classes and Objects (OOP)/12.ShallowCopy/main.cpp"
        "9-Classes and Objects (OOP)/13.DeepCopy/main.cpp"
        "9-Classes and Objects (OOP)/14.MoveConstructor/main.cpp"
        "9-Classes and Objects (OOP)/15.ConstInClasses/main.cpp"
        "9-Classes and Objects (OOP)/16.0 StaticClassMembers/main.cpp"
        "9-Classes and Objects (OOP)/16.0 StaticClassMembers/Player.cpp"
        "9-Classes and Objects (OOP)/16.0 StaticClassMembers/Player.h"
        "9-Classes and Objects (OOP)/17.Friends/Friend_class.cpp"
        "9-Classes and Objects (OOP)/17.Friends/Friend_class.h"
        "9-Classes and Objects (OOP)/17.Friends/main.cpp"
        "9-Classes and Objects (OOP)/17.Friends/Other_class.cpp"
        "9-Classes and Objects (OOP)/17.Friends/Other_class.h"
        "9-Classes and Objects (OOP)/17.Friends/Player.cpp"
        "9-Classes and Objects (OOP)/17.Friends/Player.h"
        "9-Classes and Objects (OOP)/AccessModifiers/main.cpp"
        "9-Classes and Objects (OOP)/Challenge/main.cpp"
        "9-Classes and Objects (OOP)/Challenge/Movie.cpp"
        "9-Classes and Objects (OOP)/Challenge/Movie.h"
        "9-Classes and Objects (OOP)/Challenge/Movies.cpp"
        "9-Classes and Objects (OOP)/Challenge/Movies.h"
        "9-Classes and Objects (OOP)/challenge_adding_default_constructor/adding_default_constructor.cpp"
        "9-Classes and Objects (OOP)/challenge_adding_overloaded_constructor/adding_overloaded_constructor.cpp"
        "9-Classes and Objects (OOP)/Challenge_adding_public_methods/challenge.cpp"
        "9-Classes and Objects (OOP)/ChallengeSolution/main.cpp"
        "9-Classes and Objects (OOP)/ChallengeSolution/Movie.cpp"
        "9-Classes and Objects (OOP)/ChallengeSolution/Movie.h"
        "9-Classes and Objects (OOP)/ChallengeSolution/Movies.cpp"
        "9-Classes and Objects (OOP)/ChallengeSolution/Movies.h"
        "9-Classes and Objects (OOP)/creating_accessing_objects/Challenge.cpp"
        "9-Classes and Objects (OOP)/&&operator.txt"
        "9-Classes and Objects (OOP)/classes_objects.txt"
        "9-Classes and Objects (OOP)/constructor.txt"
        "9-Classes and Objects (OOP)/static class members.txt"
        classwork/7march/7march_1.cpp
        classwork/7march/7march_2.cpp
        classwork/7march/template_2.cpp
        classwork/7march/template_3.cpp
        classwork/7march/template_4.cpp
        classwork/7march/template_5.cpp
        classwork/28feb.cpp
        classwork/template_class.cpp
        2.cpp
        garbage.txt
        t1.cpp
        t5.cpp "Algorithms-class/11 March/11march.cpp")
