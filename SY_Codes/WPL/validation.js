function validate_form()
{
    var umailFormat = document.registration.email;
    var upasswordFormat = document.registration.pswd;
    var uphoneFormat = document.registration.tel; 

    function validate_email(umailFormat)
    {
        var mailformat = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
        if(umailFormat.value.match(mailformat))
        {
            return true;
        }
        else
        {
            alert("Invalid Email ID");
            return false;
        }
    }
    function validate_pass(upasswordFormat)
    {
        var passformat = /^[a-zA-Z]\w{7,14}$/;
        if(upasswordFormat.value.match(passformat))
        {
            return true;
        }
        else
        {
            alert("Invalid Password");
            return
        }

    }
           
    
}






