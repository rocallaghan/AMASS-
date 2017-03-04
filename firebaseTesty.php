<?php
require_once 'firebaseLib.php';
// --- This is your Firebase URL
$url = 'https://amassg9.firebaseio.com/';
// --- Use your token from Firebase here
$token = 'btBpZfWpm8V5esZEt0agQz0yjqTzhTHGsF1ZM5Jf';
// --- Here is your parameter from the http GET
$arduino_data = $_GET['arduino_data'];
// --- $arduino_data_post = $_POST['name'];
// --- Set up your Firebase url structure here
$firebasePath = 'y';
/// --- Making calls
$fb = new fireBase($url, $token);
$response = $fb->push($firebasePath, $arduino_data);
sleep(2);
?>
<script src="https://www.gstatic.com/firebasejs/3.7.0/firebase.js"></script>
<script>
  // Initialize Firebase
  var config = {
    apiKey: "AIzaSyBQcWNsEPntLtnBRFlqjQgKcnDk9it2ug4",
    authDomain: "amass-gorup9.firebaseapp.com",
    databaseURL: "https://amass-gorup9.firebaseio.com",
    storageBucket: "amass-gorup9.appspot.com",
    messagingSenderId: "981504701111"
  };
  firebase.initializeApp(config);
</script>