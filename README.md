# EEL Compiler

Στόχος του project είναι η μεταγλώττιση μιάς αυτοσχέδιας αντικειμενοοστραφής
προγραμματιστικής γλώσσας που ονομάστηκε Ocean. Χρησιμοποιήθηκαν τα εργαλεία
[lex](https://silcnitc.github.io/lex.html) και [bison](https://www.gnu.org/software/bison/).
Το αρχείο εξόδου θα είναι μεταφρασμένο σε γλώσσα C με μικρές διαφορές.


## Ocean's Features

* int, int[], char, double.
* Classes.
* Objects.
* Constructors.
* Inheritance.
* Constructor overloading.
* Method overriding.
* Polymorphism.
* Abstract methods.
* Interfaces.

## Ocean's Grammar

\<program>	::= <class_type> <main><br/>
\<main>			::= main ( ) { <method_block> }<br/>
\<class_type>		::= ε | (<class>)* | (<interface>)*<br/>
\<class>			::= class id { <block> } | class id extends id { <block> }<br/>
\<interface>			::= interface id { (<interface_block>)* }<br/>
\<block>			::= <declarations> (<constructors>)* (<methods>)*<br/>
\<interface_block>		::= ε | id ( ) ;<br/>
\<declarations>		::= ε | public (<values_list>)* endpublic<br/>
\<values_list>		::= ε | <int_values> | <double_values> | <char_values> | <object_values><br/>
\<int_values>		::= int <array_or_not><br/>
\<array_or_not>		::= id <init_int_rule> | [digit] id <int_array_rule><br/>
\<int_array_rule>		::= ; | = { <many_digits> } ;<br/>
\<many_digits>		::= digit | (digit)*<br/>
\<init_int_rule>		::= ε | ; | = ( <expression> )* ;<br/>
\<double_values>		::= double id ; | double id = (<expression>)* ;<br/>
\<char_values>		::= char id ; | char id = char ;<br/>
\<object_values>		::= object id id ;<br/>
\<constructors>		::= ε | id (  <parlist> ) { <constructor_block> }<br/>
\<methods>			::= ε | void id ( <parlist> ) { (<method_block>)* }<br/>
                |  int id ( <parlist> ) { (<method_block>)* }<br/>
                | double id ( <parlist> ) { (<method_block>)* }<br/>
                | char id ( <parlist> ) { (<method_block>)* }<br/>
                | abstract id ( ) ;<br/>
\<parlist>			::= ε | <parlist_types> | (, <parlist_types> )*<br/>
\<par_int>			::= ε | id | [ digit ] id<br/>
\<constructor_block>	::= (<method_block>)*<br/>
\<method_block>		::= ε |  \<assignment> <br/>
          | \<ifstat><br/>
					| \<whilestat><br/>
					| \<switchstat><br/>
					| \<forstat><br/>
					| \<callstat><br/>
					| \<returnstat><br/>
					| \<inputstat><br/>
					| \<printstat><br/>
					| \<super><br/>
\<assignment>		::= int <local_array_or_not><br/>
					| id = (<expression>)* ;<br/>
					| double id = (<expression>)*;<br/>
					| double id ;<br/>
          | char id = (<expression>)*;<br/>
					| char id ;<br/>
					| object id id <init_object><br/>
\<local_array_or_not>	::= id <local_int> | [ digit ] id <init_array_rule><br/>
\<local_int>			::= ; | = (<expression>)* ;<br/>
\<init_object>		::= = id ( <actualpars_constructor> ) ; | ;<br/>
\<actualspars_constructor>::= ε | id | char | digit | double | (, id)* | (, char)*<br/>
          | (,  digit)* | (, double)*<br/>
\<ifstat>			::= if ( <condition> ) { (<method_block)* }<br/>
					| elif ( <condition> ) { (<method_block)* }<br/>
					| else { (<method_block)* }<br/>
\<whilestat>			::= while ( <condition> )  { (<method_block)* }<br/>
\<forstat>			::= for ( <int_values_for> id <relationaloper> <br/>
          <number_or_id>; <for_step> ) { (<method_block>)* }<br/>
\<int_values_for>		::= int id = (<expression>)* ; | id = (<expression>)* ;<br/>
\<number_of_id>		::= digit | id<br/>
\<forstep>			::= id = (<expression>)* | id = ++ | id = –<br/>
\<returnstat>			::= return (<expression>)* ;<br/>
\<switchstat>			::= switch ( id ) { (<caserule>)*}<br/>
\<caserule>			::= ε | case <id_char_digit>: (<method_block>)* break;<br/>
					| default: break;<br/>
					| default: (<method_block>)* break;<br/>
\<id_char_digit>		::= id | char | digit<br/>
\<printstat>			::= print ( (<inside_print>)* );<br/>
\<inside_print>		::= ε | (‘ <inside_apostrophe> ‘)* | (, <aftercomma>)*<br/>
\<aftercomma>		::= <inside_apostrophe> | <outside_apostrophe><br/>
\<inside_apostrophe>	::= ε | id | %d | %f | %c<br/>
\<outside_apostrophe>	::= id | digit | double | char<br/>
\<id_print>			::= id | digit | double | char<br/>
\<inputstat>			::= input ( id );<br/>
\<callstat>			::= call id <callcase><br/>
\<callcase>			::= . id ( <actualpars> ); | = id . id ( <actualpars> );<br/>
\<actualpars>		::= ε | id | char | digit | double | (, id)* | (, digit)*<br/>
          | (, double)* | (, char)*<br/>
\<super>			::= super ( <actualpars_constructor> );<br/>
\<condition>			::= <boolterm> | (|| <boolterm>)*<br/>
\<boolterm>			::= <boolfactor> | (&& <boolfactor)*<br/>
\<boolfactor>		::= ε | not <condition> | != ( <condition> ) |<br/>
					(<expression>)* <relationarloper> (<expression>)*<br/>
					| <condition> | true | false<br/>
\<expression>		::= ε | digit <operations> digit | double <operations> double<br/>
					| char | <array_expr> <operations> <array_expr><br/>
					| <array_expr> <operations> | id <operations> id<br/>
					| id <operations> digit | id <operations> double<br/>
          | double <operations> id | digit <operations> id<br/>
					| ( (<expression>)* ) | <operations> (  (<expression>)* )<br/>
					| digit <operations> | id <operations><br/>
          | (<expression>)* <operations> digit<br/>
          | (<expression>)* <operations> <array_expr><br/>
          | (<expression>)* <operations> id | double<br/>
\<array_expr>		::= id [digit]<br/>
\<operations>		::= + | - | * | / | ^ | – | ++<br/>
\<relationaloper>		::= == | < | > | <= | >= | !=<br/>


## Running the project

1. make
1. ./a.out <input_file.txt> <output_file.txt>
