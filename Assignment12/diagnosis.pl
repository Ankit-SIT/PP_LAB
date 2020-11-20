% Ankit Das - 15th November - Disease Diagnonsis using SWI-Prolog
symptom(ayush,fever).    % ayush has symptoms of dengue and diarrhoea
symptom(ayush,rash).
symptom(ayush,headache).
symptom(ayush,weakness).
symptom(ayush,nausea).
symptom(ayush,stomach_ache).

symptom(ramesh,chills). % ramesh''s symptoms don''t match any disease
symptom(ramesh,fever).
symptom(ramesh,hedache).

symptom(ajit,fever).    % ajit has symptoms of chicken_pox
symptom(ajit,rash).
symptom(ajit,body_ache).
symptom(ajit,chills).

implication(Patient,dengue) :-
    symptom(Patient,fever),
    symptom(Patient,headache),
    symptom(Patient,weakness),
    symptom(Patient,stomach_ache),
    symptom(Patient,rash),
    symptom(Patient,nausea).
    
implication(Patient,typhoid) :-
    symptom(Patient,fever),
    symptom(Patient,headache),
    symptom(Patient,weakness),
    symptom(Patient,body_ache),
    symptom(Patient,stomach_ache),
    symptom(Patient,rash),
    symptom(Patient,chills).

implication(Patient,flu) :-
    symptom(Patient,fever),
    symptom(Patient,headache),
    symptom(Patient,body_ache),
    symptom(Patient,chills).

implication(Patient,common_cold) :-
    symptom(Patient,headache),
    symptom(Patient,sneezing),
    symptom(Patient,sore_throat),
    symptom(Patient,chills),
    symptom(Patient,runny_nose).

implication(Patient,chicken_pox) :-
    symptom(Patient,fever),
    symptom(Patient,rash),
    symptom(Patient,body_ache),
    symptom(Patient,chills).

implication(Patient,diarrhoea) :-
    symptom(Patient,stomach_ache),
    symptom(Patient,fever),
    symptom(Patient,nausea).       
