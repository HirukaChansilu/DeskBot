let network_address = document.getElementById("network-address");
let device_address = document.getElementById("device-address");
let submit_btn = document.getElementsByClassName("submit-btn")[0];
let pre_ip_span = document.getElementsByClassName("pre-ip")[0];
let pre_ip_btn = document.getElementById("go-to-pre-ip");
let error_in_ip;

submit_btn.innerHTML = "Test";

if (localStorage.getItem("is_data") != "true") {
  pre_ip_span.innerHTML = "No Data";
} else {
  pre_ip_span.innerHTML = localStorage.getItem("pre_ip");

  network_address.value = localStorage.getItem("network_address");
  device_address.value = localStorage.getItem("device_address");
}

function func() {
  window.localStorage.setItem("is_data", "true");
  window.localStorage.setItem("network_address", network_address.value);
  window.localStorage.setItem("device_address", device_address.value);

  let full_ip = network_address.value + "." + device_address.value;
  error_in_ip = false;

  console.log(full_ip);

  for (let char = 0; char < full_ip.length; char++) {
    if ("0123456789.".includes(full_ip[char]) == false) {
      alert("The IP Address You Entered is Wrong, Please Check Again...");
      error_in_ip = true;
      break;
    }
  }

  if (
    full_ip.includes("..") ||
    full_ip[0] == "." ||
    full_ip[full_ip.length - 1] == "."
  ) {
    alert("The IP Address You Entered is Wrong, Please Check Again...");
    error_in_ip = true;
  }

  if (full_ip.split(".").length != 4) {
    alert("The IP Address You Entered is Wrong, Please Check Again...");
    error_in_ip = true;
  }

  if (error_in_ip == false) {
    window.localStorage.setItem("pre_ip", full_ip);
    window.location.replace("http://" + full_ip);
  }
}

function go_to_pre_ip() {
  window.location.replace("http://" + localStorage.getItem("pre_ip"));
}

submit_btn.addEventListener("click", func);
pre_ip_btn.addEventListener("click", func);
