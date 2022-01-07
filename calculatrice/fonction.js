function operation(op)
{// si op === "c" alors le texte de l'afficheur prend ""
    if(op === "C"){
        textAreaAffichage.text="";
        //sinon
    }else{
        // si op === "=" alors le texte de l'afficheur prend eval(texte de l'afficheur)
        if(op === "="){
            var res=eval(textAreaAffichage.text);
            textAreaAffichage.text=res;
        }else{
            // sinon le texte de l'afficheur prend (texte de l'afficheur)+op (ici le + permet la concaténation de chaînes)
            textAreaAffichage.text=textAreaAffichage.text+op;
        }
    }
}
