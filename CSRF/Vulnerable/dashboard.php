<?php
session_start();
$db = new SQLite3('db.sqlite');

$user = $db->querySingle("SELECT * FROM users WHERE id=1", true);
?>
<!DOCTYPE html>
<html>
<body>
    <h2>Dashboard</h2>
    <p>Logged in as: <strong><?php echo $user['username']; ?></strong></p>
    <p>Current Email: <?php echo $user['email']; ?></p>

    <a href="change_email.php">Change Email</a>
</body>
</html>
