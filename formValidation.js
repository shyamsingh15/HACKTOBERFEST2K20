const nameValidator = (name) => {
  if (name === "") return "Name Cannot be Blank";
  if (name.length < 4) return "Name Should Be Atleast 6 Characters Long ";
  if (!/^[A-Z][A-z\s]*$/.test(name)) return "Invalid name";
  return null;
};

const phonevalidator = (phone) => {
  if (phone.length < 10 || isNaN(phone)) return "Invalid Phone Number";
  return null;
};

const emailValidator = (email) => {
  console.log(email);
  if (email === "") return "Invalid Email";
  var re = /\S+@\S+\.\S+/;
  if (!re.test(email)) return "Invalid Email";
  return null;
};

const msgValidator = (msg) => {
  if (msg === "") return "Text fied cannot be empty";
  return null;
};

// ======================= //

const formValidation = (event) => {
  event.preventDefault();
  const name = document.getElementById("name").value;
  const email = document.getElementById("email").value;
  const phone = document.getElementById("phone").value;
  const msg = document.getElementById("msg").value;
  const errorContainer = document.getElementById("error-container");
  const successMsgContainer = document.getElementById("success-msg-container");

  errorContainer.innerHTML = "";

  if (nameValidator(name, errorContainer)) {
    errorContainer.innerHTML = nameValidator(name);
    return 0;
  }

  if (phonevalidator(phone, errorContainer)) {
    errorContainer.innerHTML = phonevalidator(phone);
    return 0;
  }

  if (emailValidator(email, errorContainer)) {
    errorContainer.innerHTML = emailValidator(email);
    return 0;
  }

  if (msgValidator(msg, errorContainer)) {
    errorContainer.innerHTML = msgValidator(msg);
    return 0;
  }

  errorContainer.innerHTML = "";
  successMsgContainer.innerHTML = "Form submitted succesfully";
};
