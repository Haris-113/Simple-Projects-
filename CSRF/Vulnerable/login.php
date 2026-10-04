<?php
session_start();

$_SESSION['user_id'] = 1; // auto-login for demo
header("Location: dashboard.php");
exit;
