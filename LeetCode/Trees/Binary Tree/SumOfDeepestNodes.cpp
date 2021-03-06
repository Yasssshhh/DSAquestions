Deepest Leaves Sum

Solution - I (DFS Traversal)

We can do a simple Depth-First Traversal on the Tree. We can obviously do one dfs traversal and find the depth of the deepest level and in the second dfs pass, we will add only those nodes that are on the deepest level.
But we don't actually need two passes. This can be done in just one DFS pass.

We maintain sum which will store sum of values of deepest level nodes till now and deepest which will store the depth or level of the deepest nodes. There will be following cases available to us where current Node is -
Not a Leaf Node - Traverse the left and right node of the current node.

A Leaf Node - This case will have 3 sub-cases possible -
depth > deepest - If current node is the deepest node observed till now, reset the sum to current node value and set deepest = depth.
depth == deepest - The current node is part of the deepest nodes observed till now. Add current root value to sum.
depth < deepest - This node is not the deepest node. Just ignore this node.

A NULL Node - We can't traverse any further. So just return.
Lastly, we will return the sum accumulated till now. The finaly value stored in sum will contain only the sum of value of the nodes (leaves) at deepest level. The implementation of this is given below -


int deepest = 0, sum = 0;
int deepestLeavesSum(TreeNode* root, int depth = 0) {
	if(!root) return 0;  // current node is NULL - just return.
	if(!root -> left && !root -> right) // if current is a leaf node
		if(depth == deepest) sum += root -> val;  // if depth is exactly equal to deepest, add to sum
		else if(depth > deepest) sum = root -> val, deepest = depth; // found a more deeper leaf node, reset sum and update deepest
	deepestLeavesSum(root -> left, depth + 1);   // recurse for the left, 
	deepestLeavesSum(root -> right, depth + 1);  // and the right node of the current node
	return sum; // finally return the sum accumulated till now which will be sum of value of deepest leaves
}

Time Complexity : O(N), where, N is the total number of nodes in the given Tree.
Space Complexity : O(N), In the worst case, the tree may have all nodes only to the left or right making the max recursion depth equal to N.

Solution - II (BFS Traversal)

We can also do a Breadth-First Traversal or Level-Order Traversal.
In this we visit each depth level one by one. Just reset sum to 0 at start of each depth level and add the values of all nodes on that level. At the end, sum will store the sum of all values of the last level or the sum of values or deepest leaves.

int deepestLeavesSum(TreeNode* root) {
	int sum = 0, n;
	queue<TreeNode*> q; // required for level-order traversal
	q.push(root);
	while(!q.empty()){
		sum = 0, n = size(q); // reset sum when deeper level is reached and accumulate for that level
		for(int i = 0; i < n; i++){
			auto top = q.front(); q.pop();
			sum += top -> val;     
			if(top -> left) q.push(top -> left);
			if(top -> right) q.push(top -> right);
		}                
	}
	return sum; // final value held by 'sum' will be sum of values of nodes at the deepest level
}