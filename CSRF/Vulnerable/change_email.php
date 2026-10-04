<?php
session_start();
$db = new SQLite3('db.sqlite');

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $newEmail = $_POST['email'];
    $db->exec("UPDATE users SET email='$newEmail' WHERE id=1");
    echo "Email updated to: $newEmail";
    exit;
}
?>
<!DOCTYPE html>
<html>
<body>
    <h2>Change Email</h2>
    <form method="POST">
        <input name="email" type="text" placeholder="New Email">
        <button type="submit">Update</button>
    </form>
</body>
</html>
