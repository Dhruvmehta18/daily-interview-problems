package day27;

import java.util.ArrayList;
import java.util.HashMap;

public class DuplicateSubtree {

	class Node {
		int value;
		Node left;
		Node right;

		Node(int value) {
			this.value = value;
		}

		Node(int value, Node left, Node right) {
			this.value = value;
			this.left = left;
			this.right = right;
		}
	}

	private String inOrderHelper(Node root, HashMap<String, ArrayList<Node>> map) {
		if (root == null) {
			return "";
		}

		String inorderStr = "(";
		inorderStr += inOrderHelper(root.left, map);
		inorderStr += root.value;
		inorderStr += inOrderHelper(root.right, map);

		if (map.containsKey(inorderStr)) {
			map.get(inorderStr).add(root);
			map.put(inorderStr, map.get(inorderStr));
		} else {
			ArrayList<Node> nodes = new ArrayList<Node>();
			nodes.add(root);
			map.put(inorderStr, nodes);
		}

		return inorderStr;
	}

	private HashMap<String, ArrayList<Node>> inorder(Node root) {
		HashMap<String, ArrayList<Node>> map = new HashMap<String, ArrayList<Node>>();

		inOrderHelper(root, map);

		return map;
	}

	private ArrayList<ArrayList<Node>> dupTreesHelper(Node root) {
		HashMap<String, ArrayList<Node>> map = inorder(root);
		ArrayList<ArrayList<Node>> result = new ArrayList<ArrayList<Node>>();
		for (ArrayList<Node> list : map.values()) {
			result.add(list);
		}

		return result;
	}

	public ArrayList<ArrayList<Node>> dupTrees(Node root) {
		if (root == null || root.left == null || root.right == null) {
			return new ArrayList<>();
		}
		return dupTreesHelper(root);
	}

	public static void main(String[] args) {
		Node n3_1 = Node(3);
		Node n2_1 = Node(2, n3_1);
		Node n3_2 = Node(3);
		Node n2_2 = Node(2, n3_2);
		Node n1 = Node(1, n2_1, n2_2);
	}
}
